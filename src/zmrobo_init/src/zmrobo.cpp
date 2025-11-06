#include "zmrobo.h"
#include "Quaternion_Solution.h"
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

sensor_msgs::msg::Imu Mpu6050; // Instantiate IMU object

/**************************************
Ported to ROS2 Foxy
***************************************/
int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("zmrobo_init");
  auto robot = std::make_shared<turn_on_robot>(node);
  robot->Control();
  RCLCPP_INFO(node->get_logger(), "zmrobo node has turned on ");
  rclcpp::shutdown();
  return 0;
}

/**************************************
turn_on_robot constructor (ROS2 version)
***************************************/
turn_on_robot::turn_on_robot(const rclcpp::Node::SharedPtr &node_ptr)
    : node(node_ptr), Sampling_Time(0), Power_voltage(0)
{
  memset(&Robot_Pos, 0, sizeof(Robot_Pos));
  memset(&Robot_Vel, 0, sizeof(Robot_Vel));
  memset(&Receive_Data, 0, sizeof(Receive_Data));
  memset(&Send_Data, 0, sizeof(Send_Data));
  memset(&Mpu6050_Data, 0, sizeof(Mpu6050_Data));

  // Declare and get parameters
  node->declare_parameter<std::string>("usart_port_name", "/dev/zmrobo_controller");
  node->declare_parameter<int>("serial_baud_rate", 115200);
  node->declare_parameter<std::string>("cmd_vel", "cmd_vel");
  node->declare_parameter<std::string>("akm_cmd_vel", "akm_cmd_vel");
  node->declare_parameter<std::string>("odom_frame_id", "odom");
  node->declare_parameter<std::string>("robot_frame_id", "base_link");
  node->declare_parameter<std::string>("gyro_frame_id", "gyro_link");

  node->get_parameter("usart_port_name", usart_port_name);
  node->get_parameter("serial_baud_rate", serial_baud_rate);
  node->get_parameter("cmd_vel", cmd_vel);
  node->get_parameter("akm_cmd_vel", akm_cmd_vel);
  node->get_parameter("odom_frame_id", odom_frame_id);
  node->get_parameter("robot_frame_id", robot_frame_id);
  node->get_parameter("gyro_frame_id", gyro_frame_id);

  // Create publishers
  voltage_publisher = node->create_publisher<std_msgs::msg::Float32>("PowerVoltage", 10);
  odom_publisher = node->create_publisher<nav_msgs::msg::Odometry>("odom", 50);
  imu_publisher = node->create_publisher<sensor_msgs::msg::Imu>("mobile_base/sensors/imu_data", 20);

  // Subscriptions
  Cmd_Vel_Sub = node->create_subscription<geometry_msgs::msg::Twist>(
      cmd_vel, 100, std::bind(&turn_on_robot::Cmd_Vel_Callback, this, std::placeholders::_1));
  Akm_cmd_Vel_Sub = node->create_subscription<ackermann_msgs::msg::AckermannDriveStamped>(
      akm_cmd_vel, 100, std::bind(&turn_on_robot::Akm_cmd_Vel_Callback, this, std::placeholders::_1));

  RCLCPP_INFO(node->get_logger(), "Data ready");

  try
  {
    Stm32_Serial.setPort(usart_port_name);
    Stm32_Serial.setBaudrate(serial_baud_rate);
    serial::Timeout _time = serial::Timeout::simpleTimeout(2000);
    Stm32_Serial.setTimeout(_time);
    Stm32_Serial.open();
  }
  catch (serial::IOException &e)
  {
    RCLCPP_ERROR(node->get_logger(), "zmrobo can not open serial port, check the cable!");
  }

  if (Stm32_Serial.isOpen())
  {
    RCLCPP_INFO(node->get_logger(), "zmrobo serial port opened");
  }
}

/**************************************
Destructor
***************************************/
turn_on_robot::~turn_on_robot()
{
  Send_Data.tx[0] = FRAME_HEADER;
  Send_Data.tx[1] = Send_Data.tx[2] = 0;
  Send_Data.tx[3] = Send_Data.tx[4] = 0;
  Send_Data.tx[5] = Send_Data.tx[6] = 0;
  Send_Data.tx[7] = Send_Data.tx[8] = 0;
  Send_Data.tx[9] = Check_Sum(9, SEND_DATA_CHECK);
  Send_Data.tx[10] = FRAME_TAIL;

  try
  {
    Stm32_Serial.write(Send_Data.tx, sizeof(Send_Data.tx));
  }
  catch (serial::IOException &e)
  {
    RCLCPP_ERROR(node->get_logger(), "Unable to send stop command via serial");
  }

  Stm32_Serial.close();
  RCLCPP_INFO(node->get_logger(), "Shutting down zmrobo");
}
