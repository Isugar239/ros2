#!/usr/bin/env python3
import math
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from turtlesim.srv import Spawn

class TurtleFollower(Node):
    def __init__(self):
        super().__init__('turtle_follower')

        self.declare_parameter('leader_name', 'turtle1')
        self.declare_parameter('follower_name', 'turtle2')
        self.declare_parameter('follow_distance', 1.0)
        self.declare_parameter('linear_k', 1.0)
        self.declare_parameter('angular_k', 4.0)

        self.leader_name = self.get_parameter('leader_name').get_parameter_value().string_value
        self.follower_name = self.get_parameter('follower_name').get_parameter_value().string_value
        self.follow_distance = float(self.get_parameter('follow_distance').get_parameter_value().double_value)
        self.linear_k = float(self.get_parameter('linear_k').get_parameter_value().double_value)
        self.angular_k = float(self.get_parameter('angular_k').get_parameter_value().double_value)

        self.leader_pose = Pose()
        self.follower_pose = Pose()
        self.create_subscription(Pose, f'/{self.leader_name}/pose', self._on_leader_pose, 10)
        self.create_subscription(Pose, f'/{self.follower_name}/pose', self._on_follower_pose, 10)

        self.cmd_pub = self.create_publisher(Twist, f'/{self.follower_name}/cmd_vel', 10)

        self.timer = self.create_timer(0.1, self._control_loop)

        self.spawn_client = self.create_client(Spawn, f'/spawn')
        while not self.spawn_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Service /spawn not available, waiting...')

        self.spawn_client.call_async(Spawn.Request(x=self.follower_pose.x, y=self.follower_pose.y, theta=self.follower_pose.theta))

    def _on_leader_pose(self, msg: Pose):
        self.leader_pose = msg

    def _on_follower_pose(self, msg: Pose):
        self.follower_pose = msg

    def _control_loop(self):
        target_x = self.leader_pose.x 
        target_y = self.leader_pose.y 

        dx = target_x - self.follower_pose.x
        dy = target_y - self.follower_pose.y
        distance = math.sqrt(dx * dx + dy * dy)

        desired_angle = math.atan2(dy, dx) 
        angle_error = desired_angle - self.follower_pose.theta
        angle_error = math.atan2(math.sin(angle_error), math.cos(angle_error)) * 180 / math.pi
        twist = Twist()
        twist.linear.x = self.linear_k * distance

        twist.angular.z = self.angular_k * angle_error


        self.cmd_pub.publish(twist)

def main(args=None):
    rclpy.init(args=args)
    node = TurtleFollower()
    rclpy.spin(node)

    # По завершении
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
