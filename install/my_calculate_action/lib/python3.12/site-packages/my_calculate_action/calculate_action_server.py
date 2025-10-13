#!/usr/bin/env python3
import math
import time

import rclpy
from rclpy.node import Node
from rclpy.action import ActionServer, GoalResponse, CancelResponse

# Импортируем наш Action из пакета my_action_interface
from my_action_interface.action import SummCalculate

class SummCalculateActionServer(Node):
    """
    Action-сервер, который считает сумму целых чисел от a до b, a <= b
    Каждое сложение 'замедляем' на 0.1c, чтобы эмулировать долгий процесс.
    Публикуем feedback (сколько 'шагов' осталось).
    """

    def __init__(self):
        super().__init__('summ_calculate_action_server')

        # Создаём Action-сервер
        self._action_server = ActionServer(
            self,
            SummCalculate,
            'summ_calculate',  # имя действия в ROS
            execute_callback=self.execute_callback,
            goal_callback=self.goal_callback,
        )

        self.get_logger().info("SummCalculate Action Server Запущен!")

    def goal_callback(self, goal_request):
        """
        Вызывается при поступлении нового Goal.
        Можно проверить валидность и принять/отклонить.
        """
        self.get_logger().info(f'Получен goal: a={goal_request.a}, b={goal_request.b}')
        if goal_request.a > 1000 or goal_request.b > 1000:
            return GoalResponse.REJECT
        return GoalResponse.ACCEPT

    def execute_callback(self, goal_handle):
        """
        Вызывается при принятии цели.
        """
        self.get_logger().info("Начинаем вычисление суммы...")

        a = int(goal_handle.request.a)
        b = int(goal_handle.request.b)

        if a > b:
            self.get_logger().error("Некорректный диапазон (a>b), отменяем задачу.")
            goal_handle.abort()
            result = SummCalculate.Result()
            result.success = False
            return result

        current_sum = 0
        steps_done = 0

        # Для наглядности, каждые 0.1с складываем одно число:
        total_numbers = (b - a + 1)
        for x in range(a, b+1):
            current_sum += x
            steps_done += 1
            # Публикуем feedback (сколько осталось)
            feedback = SummCalculate.Feedback()
            left_count = total_numbers - steps_done
            # Например, пишем "сколько ещё осталось сложить"
            feedback.left_to_result = left_count
            goal_handle.publish_feedback(feedback)
            time.sleep(0.1)  # эмуляция "долгих" вычислений (10 шагов/сек)

        self.get_logger().info(f"Сумма = {current_sum} (от a={a} до b={b}).")

        # Завершаем задачку успехом
        goal_handle.succeed()
        result = SummCalculate.Result()
        result.success = True
        return result


def main(args=None):
    rclpy.init(args=args)
    node = SummCalculateActionServer()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        node.get_logger().info("Остановка сервера по Ctrl+C")
    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == '__main__':
    main()
