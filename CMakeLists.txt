cmake_minimum_required(VERSION 3.9)
project(eecs560)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SRC Lab01/*.cpp Lab01/*.h)

add_executable(Lab01 ${SRC})