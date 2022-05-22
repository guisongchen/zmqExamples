cmake_minimum_required(VERSION 3.0)
project(zmq_test)

add_executable(hwserver basics/hello_world_server.cpp)
target_link_libraries(hwserver zmq)

add_executable(hwclient basics/hello_world_client.cpp)
target_link_libraries(hwclient zmq)
