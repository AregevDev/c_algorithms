cmake_minimum_required(VERSION 3.17)
project(c_algorithms C)

set(CMAKE_C_STANDARD 11)

add_library(c_algorithms INTERFACE)
target_include_directories(c_algorithms INTERFACE include)

add_executable(sample src/sample/main.c)
target_link_libraries(sample PRIVATE c_algorithms)
