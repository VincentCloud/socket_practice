cmake_minimum_required(VERSION 3.10)
project(socket C)

set(CMAKE_C_STANDARD 99)

add_executable(client client.c)
add_executable(server server.c)
add_executable(test test.c)
add_executable(test2 test2.c)

