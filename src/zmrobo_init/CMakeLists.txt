cmake_minimum_required(VERSION 3.10)
project(zmrobo_init)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(nav_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(ackermann_msgs REQUIRED)
find_package(tf2 REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(tf2_geometry_msgs REQUIRED)

find_package(serial REQUIRED)  # из пакета serial-ros2

add_compile_options(-g -std=c++17)

# Включаем заголовки
include_directories(
  include
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Добавляем include-директории из serial (важно!)
if(TARGET serial)
  get_target_property(SERIAL_INCLUDE_DIRS serial INTERFACE_INCLUDE_DIRECTORIES)
  include_directories(${SERIAL_INCLUDE_DIRS})
endif()
# Добавляем include-директории для serial
include_directories(
  include
  include/${PROJECT_NAME}
  ${CMAKE_CURRENT_SOURCE_DIR}/../serial/include        # путь к исходникам
  ${CMAKE_INSTALL_PREFIX}/include                      # стандартный include путь
  ${CMAKE_CURRENT_SOURCE_DIR}/../../install/serial/include  # путь к установленным хедерам serial
)

add_executable(zmrobo_node
  src/zmrobo.cpp
  src/Quaternion_Solution.cpp
)

ament_target_dependencies(zmrobo_node
  rclcpp
  geometry_msgs
  nav_msgs
  sensor_msgs
  std_msgs
  ackermann_msgs
  tf2
  tf2_ros
  tf2_geometry_msgs
  serial
)

install(TARGETS zmrobo_node
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY include/
  DESTINATION include/
)

ament_package()
