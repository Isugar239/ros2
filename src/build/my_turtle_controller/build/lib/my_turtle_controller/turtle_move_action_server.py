#!/usr/bin/env python3
import math
import rclpy
from rclpy.action import ActionServer, CancelResponse, GoalResponse
from rclpy.node import Node

from geometry_msgs.msg import Twist
from turtlesim.msg import Pose

from my_action_interface.action import MoveTo


class TurtleMoveActionServer(Node):
    def __init__(self):
        super().__init__('turtle_move_action_server')

        self.cmd_pub = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        self.pose_sub = self.create_subscription(Pose, '/turtle1/pose', self._on_pose, 10)

        self.current_pose = Pose()

        self.linear_k = 1.0
        self.angular_k = 4.0
        self.arrival_tolerance = 0.01

        # Текущая цель
        self.target_x = 0.0
        self.target_y = 0.0
        self.is_moving = False
        self.current_goal_handle = None

        self.timer = self.create_timer(0.1, self.control_loop)

        self._action_server = ActionServer(
            self,
            MoveTo,
            'move_to',
            execute_callback=self.execute_callback,
            goal_callback=self.goal_callback,
            cancel_callback=self.cancel_callback,
        )

    def _on_pose(self, msg: Pose):
        self.current_pose = msg

    def goal_callback(self, goal_request: MoveTo.Goal):
        self.get_logger().info(f"Новая цель принята: x={goal_request.x}, y={goal_request.y}")
        return GoalResponse.ACCEPT

    def cancel_callback(self, goal_handle):
        self.get_logger().info('cancel')
        self._stop()
        return CancelResponse.ACCEPT

    def execute_callback(self, goal_handle):
        self.get_logger().info('start')
        
        # Устанавливаем новую цель
        self.target_x = goal_handle.request.x
        self.target_y = goal_handle.request.y
        self.is_moving = True
        self.current_goal_handle = goal_handle

        while self.is_moving and rclpy.ok():
            rclpy.spin_once(self, timeout_sec=0.1)

        if self.current_goal_handle == goal_handle:
            if goal_handle.is_cancel_requested:
                goal_handle.canceled()
                return MoveTo.Result(success=False)
            else:
                self.get_logger().info('reached')
                goal_handle.succeed()
                return MoveTo.Result(success=True)

    def control_loop(self):
        if not self.is_moving or self.current_goal_handle is None:
            return

        dx = self.target_x - self.current_pose.x
        dy = self.target_y - self.current_pose.y
        distance = math.sqrt(dx * dx + dy * dy)

        if distance < self.arrival_tolerance:
            self._stop()
            self.is_moving = False
            self.current_goal_handle = None
            return

        # P-control
        desired_angle = math.atan2(dy, dx)
        angle_error = desired_angle - self.current_pose.theta
        angle_error = math.atan2(math.sin(angle_error), math.cos(angle_error))

        twist = Twist()
        twist.linear.x = min(2.0, self.linear_k * distance)
        twist.angular.z = self.angular_k * angle_error
        twist.angular.z = max(-2.0, min(2.0, twist.angular.z))
        self.cmd_pub.publish(twist)

        # Отправляем обратную связь
        if self.current_goal_handle:
            feedback_msg = MoveTo.Feedback()
            feedback_msg.distance_remaining = float(distance)
            self.current_goal_handle.publish_feedback(feedback_msg)

    def _stop(self):
        twist = Twist()
        twist.linear.x = 0.0
        twist.angular.z = 0.0
        self.cmd_pub.publish(twist)


def main(args=None):
    rclpy.init(args=args)
    node = TurtleMoveActionServer()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()


