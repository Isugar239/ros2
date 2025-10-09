from setuptools import find_packages, setup

package_name = 'my_turtle_controller'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        ('share/' + package_name + '/launch', [
            'launch/follow_with_teleop.launch.py',
            'launch/multi_followers_with_teleop.launch.py',
        ]),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='za1van',
    maintainer_email='za1van@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
#    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
'turtle_mover = my_turtle_controller.turtle_mover:main',
'turtle_figure8 = my_turtle_controller.turtle_figure8:main',
'turtle_pose_follower = my_turtle_controller.turtle_pose_follower:main',
'turtle_follower_spawner = my_turtle_controller.follower_spawner:main',
            'turtle_move_action_server = my_turtle_controller.turtle_move_action_server:main',
            'turtle_move_action_client = my_turtle_controller.turtle_move_action_client:main',
  ],
    },
)
