import rclpy
from rclpy.node import Node
from std_msgs.msg import String
from geometry_msgs.msg import Twist
import time
class Turtle(Node):
    def __init__(self):
        super().__init__('turtle_mosh')
        self.publisher = self.create_publisher(Twist, 'cmd_vel', 10)
        self.twist_msg = Twist()
        self.twist_msg.linear.x = 0
        self.twist_msg.linear.y = 0
        self.twist_msg.angular.z = 0
        self.dt = 0.01

    def nUgol(self, a, n):
        if(a < 0.5 or a > 2):
            self.get_logger().info("a is out of bounds")
        if(n < 3 or n > 15):
            self.get_logger.info("angle is out of bounds")

        angle = ((n-2) * 180)/n
        for i in range(n):
            self.twist_msg.linear.x = a/self.dt
            self.twist_msg.angular.z = angle/self.dt
            self.publisher.publish(self.twist_msg)
            time.sleep(self.dt)
            self.twist_msg.linear.x = 0
            self.twist_msg.angular.z = 0
            self.publisher.publish(self.twist_msg)

