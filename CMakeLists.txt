cmake_minimum_required(VERSION 3.0)
project(zmq_test)

# add_executable(hwserver basics/hello_world_server.cpp)
# target_link_libraries(hwserver zmq)
# 
# add_executable(hwclient basics/hello_world_client.cpp)
# target_link_libraries(hwclient zmq)

add_executable(wupub basics/weather_update_publisher.cpp)
target_link_libraries(wupub zmq)

add_executable(wusub basics/weather_update_subscriber.cpp)
target_link_libraries(wusub zmq)