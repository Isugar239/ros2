#!/usr/bin/env python3
import math
import rclpy
from rclpy.node import Node

from geometry_msgs.msg import Twist
from turtlesim.msg import Pose
from turtlesim.srv import Spawn


class TurtleFollowerSpawner(Node):
    def __init__(self):
        super().__init__('turtle_follower_spawner')

        # Параметры: кого следовать и кто следует
        self.declare_parameter('leader_name', 'turtle1')
        self.declare_parameter('follower_name', 'turtle2')
        self.declare_parameter('follower_x', 5.0)
        self.declare_parameter('follower_y', 5.0)
        self.declare_parameter('follower_theta', 0.0)

        self.leader_name = self.get_parameter('leader_name').get_parameter_value().string_value
        self.follower_name = self.get_parameter('follower_name').get_parameter_value().string_value
        self.follower_x = float(self.get_parameter('follower_x').get_parameter_value().double_value)
        self.follower_y = float(self.get_parameter('follower_y').get_parameter_value().double_value)
        self.follower_theta = float(self.get_parameter('follower_theta').get_parameter_value().double_value)

        # Клиент к сервису /spawn
        self.spawn_client = self.create_client(Spawn, 'spawn')
        if not self.spawn_client.wait_for_service(timeout_sec=5.0):
            self.get_logger().warn('Service /spawn not available yet, waiting...')
        while not self.spawn_client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for /spawn service...')

        # Спауним ведомую черепаху
        req = Spawn.Request()
        req.x = float(self.follower_x)
        req.y = float(self.follower_y)
        req.theta = float(self.follower_theta)
        req.name = self.follower_name

        future = self.spawn_client.call_async(req)
        rclpy.spin_until_future_complete(self, future)
        if future.result() is None:
            self.get_logger().error('Failed to spawn follower turtle')
            raise RuntimeError('Spawn failed')
        else:
            self.get_logger().info(f"Spawned follower turtle: {future.result().name}")

        # Подписчик на позу лидера
        leader_pose_topic = f'/{self.leader_name}/pose'
        self.pose_subscriber = self.create_subscription(
            Pose,
            leader_pose_topic,
            self.leader_pose_callback,
            10
        )

        # Подписчик на позу ведомого
        follower_pose_topic = f'/{self.follower_name}/pose'
        self.follower_pose_sub = self.create_subscription(
            Pose,
            follower_pose_topic,
            self.follower_pose_callback,
            10
        )

        # Публикатор команд для ведомого
        follower_cmd_vel_topic = f'/{self.follower_name}/cmd_vel'
        self.cmd_pub = self.create_publisher(Twist, follower_cmd_vel_topic, 10)

        # Текущие позы
        self.leader_pose = Pose()
        self.follower_pose = Pose()

        # Таймер управления
        self.timer = self.create_timer(0.1, self.control_loop)

        # Коэффициенты регулятора
        self.linear_k = 1.0
        self.angular_k = 4.0

        # Целевая дистанция следования (метров)
        self.follow_distance = 1.0

    def leader_pose_callback(self, msg: Pose):
        self.leader_pose = msg

    def control_loop(self):
        # Целевая точка: позади лидера на follow_distance по его ориентации
        target_x = self.leader_pose.x - self.follow_distance * math.cos(self.leader_pose.theta)
        target_y = self.leader_pose.y - self.follow_distance * math.sin(self.leader_pose.theta)

        dx = target_x - self.follower_pose.x
        dy = target_y - self.follower_pose.y
        distance = math.sqrt(dx*dx + dy*dy)

        desired_angle = math.atan2(dy, dx)
        angle_error = desired_angle - self.follower_pose.theta
        angle_error = math.atan2(math.sin(angle_error), math.cos(angle_error))

        twist = Twist()
        twist.linear.x = self.linear_k * distance
        if twist.linear.x > 2.0:
            twist.linear.x = 2.0

        twist.angular.z = self.angular_k * angle_error
        if twist.angular.z > 2.0:
            twist.angular.z = 2.0
        elif twist.angular.z < -2.0:
            twist.angular.z = -2.0

        self.cmd_pub.publish(twist)

    def follower_pose_callback(self, msg: Pose):
        self.follower_pose = msg


def main(args=None):
    rclpy.init(args=args)
    node = TurtleFollowerSpawner()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()


