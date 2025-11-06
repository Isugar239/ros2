#ifndef __ZMROBO_H_
#define __ZMROBO_H_

#include "rclcpp/rclcpp.hpp"
#include <iostream>
#include <string.h>
#include <string> 
#include <math.h>
#include <stdlib.h>    
#include <unistd.h>      
#include <sys/types.h>
#include <sys/stat.h>
#include <serial/serial.h>
#include <fcntl.h>          
#include <stdbool.h>
#include <tf2/LinearMath/Quaternion.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.hpp>

#include "std_msgs/msg/string.hpp"
#include "std_msgs/msg/float32.hpp"
#include "nav_msgs/msg/odometry.hpp"
#include "geometry_msgs/msg/pose.hpp"
#include "geometry_msgs/msg/vector3.hpp"
#include "geometry_msgs/msg/pose_with_covariance_stamped.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "ackermann_msgs/msg/ackermann_drive_stamped.hpp"
#include "sensor_msgs/msg/imu.hpp"

using namespace std;

// ==================== Макросы ====================
#define SEND_DATA_CHECK   1
#define READ_DATA_CHECK   0
#define FRAME_HEADER      0X7B
#define FRAME_TAIL        0X7D
#define RECEIVE_DATA_SIZE 24
#define SEND_DATA_SIZE    11
#define PI                3.1415926f

#define GYROSCOPE_RATIO   0.00026644f
#define ACCEl_RATIO       1671.84f  	

extern sensor_msgs::msg::Imu Mpu6050;

// ==================== Ковариационные матрицы ====================
const double odom_pose_covariance[36]   = {1e-3, 0, 0, 0, 0, 0,
                                           0, 1e-3, 0, 0, 0, 0,
                                           0, 0, 1e6, 0, 0, 0,
                                           0, 0, 0, 1e6, 0, 0,
                                           0, 0, 0, 0, 1e6, 0,
                                           0, 0, 0, 0, 0, 1e3};

const double odom_pose_covariance2[36]  = {1e-9, 0, 0, 0, 0, 0,
                                           0, 1e-3, 1e-9, 0, 0, 0,
                                           0, 0, 1e6, 0, 0, 0,
                                           0, 0, 0, 1e6, 0, 0,
                                           0, 0, 0, 0, 1e6, 0,
                                           0, 0, 0, 0, 0, 1e-9};

const double odom_twist_covariance[36]  = {1e-3, 0, 0, 0, 0, 0,
                                           0, 1e-3, 0, 0, 0, 0,
                                           0, 0, 1e6, 0, 0, 0,
                                           0, 0, 0, 1e6, 0, 0,
                                           0, 0, 0, 0, 1e6, 0,
                                           0, 0, 0, 0, 0, 1e3};

const double odom_twist_covariance2[36] = {1e-9, 0, 0, 0, 0, 0,
                                           0, 1e-3, 1e-9, 0, 0, 0,
                                           0, 0, 1e6, 0, 0, 0,
                                           0, 0, 0, 1e6, 0, 0,
                                           0, 0, 0, 0, 1e6, 0,
                                           0, 0, 0, 0, 0, 1e-9};

// ==================== Структуры данных ====================
typedef struct __Vel_Pos_Data_
{
	float X;
	float Y;
	float Z;
} Vel_Pos_Data;

typedef struct __MPU6050_DATA_
{
	short accele_x_data; 
	short accele_y_data; 	
	short accele_z_data; 
    short gyros_x_data; 
	short gyros_y_data; 	
	short gyros_z_data; 
} MPU6050_DATA;

typedef struct _SEND_DATA_  
{
	uint8_t tx[SEND_DATA_SIZE];
	float X_speed;	       
	float Y_speed;           
	float Z_speed;         
	unsigned char Frame_Tail; 
} SEND_DATA;

typedef struct _RECEIVE_DATA_     
{
	uint8_t rx[RECEIVE_DATA_SIZE];
	uint8_t Flag_Stop;
	unsigned char Frame_Header;
	float X_speed;  
	float Y_speed;  
	float Z_speed;  
	float Power_Voltage;	
	unsigned char Frame_Tail;
} RECEIVE_DATA;

// ==================== Основной класс ====================
class turn_on_robot
{
public:
	explicit turn_on_robot(const rclcpp::Node::SharedPtr & node_ptr);
	~turn_on_robot();

	void Control();   // Основной цикл управления

private:
	rclcpp::Node::SharedPtr node;  // ROS2 нода
	rclcpp::Time _Now, _Last_Time;
	float Sampling_Time;

	// Подписчики
	rclcpp::Subscription<geometry_msgs::msg::Twist>::SharedPtr Cmd_Vel_Sub;
	rclcpp::Subscription<ackermann_msgs::msg::AckermannDriveStamped>::SharedPtr Akm_cmd_Vel_Sub;

	// Паблишеры
	rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr odom_publisher;
	rclcpp::Publisher<sensor_msgs::msg::Imu>::SharedPtr imu_publisher;
	rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr voltage_publisher;

	// Callback'и
	void Akm_cmd_Vel_Callback(const ackermann_msgs::msg::AckermannDriveStamped::SharedPtr akm_ctl);
	void Cmd_Vel_Callback(const geometry_msgs::msg::Twist::SharedPtr twist_aux);

	// Публикации
	void Publish_Odom();
	void Publish_ImuSensor();
	void Publish_Voltage();

	// Работа с датчиками
	bool Get_Sensor_Data();
	unsigned char Check_Sum(unsigned char Count_Number, unsigned char mode);
	short IMU_Trans(uint8_t Data_High, uint8_t Data_Low);
	float Odom_Trans(uint8_t Data_High, uint8_t Data_Low);

	// Данные и параметры
	string usart_port_name, robot_frame_id, gyro_frame_id, odom_frame_id, cmd_vel, akm_cmd_vel;
	int serial_baud_rate;

	RECEIVE_DATA Receive_Data;
	SEND_DATA Send_Data;
	Vel_Pos_Data Robot_Pos;
	Vel_Pos_Data Robot_Vel;
	MPU6050_DATA Mpu6050_Data;
	float Power_voltage;

	serial::Serial Stm32_Serial;
};

#endif
