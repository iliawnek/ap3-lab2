cmake_minimum_required(VERSION 3.6)
project(ap3_lab2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(echo echo.c)
add_executable(find findmain.c)
