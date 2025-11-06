#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from geometry_msgs.msg import Twist

class TurtleMover(Node):
    def __init__(self):
        super().__init__('turtle_mover')
        # Создаем паблишера (publisher) в топик /turtle1/cmd_vel с типом сообщения Twist длиной очереди 10 сообщений
        self.publisher_ = self.create_publisher(Twist, '/turtle1/cmd_vel', 10)
        # Таймер срабатывает каждые 0.1 сек
        timer_period = 0.1
        self.timer = self.create_timer(timer_period, self.move_turtle)

        self.side_length = 2.0        
        self.linear_speed = 2.0       
        self.turn_angle = 1.57079632679 
        self.angular_speed = 1.57079632679  

       
        self.move_duration_sec = self.side_length / self.linear_speed
        self.turn_duration_sec = self.turn_angle / self.angular_speed


        self.state = 'move'
        self.sides_done = 0  
        self.state_started_at = self.get_clock().now()

        self.twist_msg = Twist()

    def move_turtle(self):
        now = self.get_clock().now()
        elapsed = (now - self.state_started_at).nanoseconds / 1e9

        if self.state == 'move':
            # Двигаемся вперед по прямой
            self.twist_msg.linear.x = self.linear_speed
            self.twist_msg.angular.z = 0.0
            if elapsed >= self.move_duration_sec:
                self.state = 'turn'
                self.state_started_at = now
                self.sides_done += 1
        else:
            self.twist_msg.linear.x = 0.0
            self.twist_msg.angular.z = self.angular_speed
            if elapsed >= self.turn_duration_sec:
                self.state = 'move'
                self.state_started_at = now
                if self.sides_done >= 4:
                    self.sides_done = 0

        self.publisher_.publish(self.twist_msg)
        self.get_logger().info('cmd_vel: linear=%.2f, angular=%.2f | state=%s side=%d' % (
            self.twist_msg.linear.x,
            self.twist_msg.angular.z,
            self.state,
            self.sides_done
        ))

def main(args=None):
    rclpy.init(args=args)
    node = TurtleMover()
    rclpy.spin(node)

    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()

