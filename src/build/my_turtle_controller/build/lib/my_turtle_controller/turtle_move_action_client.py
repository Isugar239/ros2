#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient

from my_action_interface.action import MoveTo


class TurtleMoveActionClient(Node):
    def __init__(self):
        super().__init__('turtle_move_action_client')
        self._client = ActionClient(self, MoveTo, 'move_to')

    def send_goal(self, x: float, y: float):
        if not self._client.wait_for_server(timeout_sec=5.0):
            self.get_logger().error('Сервер экшена недоступен')
            return False

        goal_msg = MoveTo.Goal()
        goal_msg.x = float(x)
        goal_msg.y = float(y)

        self.get_logger().info(f'send goal: x={goal_msg.x}, y={goal_msg.y}')

        send_goal_future = self._client.send_goal_async(
            goal_msg,
            feedback_callback=self._feedback_cb,
        )
        rclpy.spin_until_future_complete(self, send_goal_future)
        goal_handle = send_goal_future.result()
        if not goal_handle.accepted:
            self.get_logger().warn('canceled')
            return False

        get_result_future = goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, get_result_future)
        result = get_result_future.result().result
        self.get_logger().info(f'Результат: success={result.success}')
        return bool(result.success)

    def _feedback_cb(self, feedback_msg: MoveTo.Feedback):
        feedback = feedback_msg.feedback
        self.get_logger().info(f'Остаток: {feedback.distance_remaining:.3f}')


def main(args=None):
    rclpy.init(args=args)
    node = TurtleMoveActionClient()
    try:
        while rclpy.ok():
            user_input = input('\nx y ').strip()
            if not user_input:
                continue
            if user_input.lower() == 'q':
                break
            parts = user_input.split()
            if len(parts) < 2:
                print('format error')
                continue
            try:
                x = float(parts[0])
                y = float(parts[1])
            except ValueError:
                print('math error')
                continue

            node.send_goal(x, y)
    except KeyboardInterrupt:
        pass
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()


