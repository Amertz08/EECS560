cmake_minimum_required(VERSION 3.9)
project(eecs560)

set(CMAKE_CXX_STANDARD 11)

file(GLOB SRC_01 Lab01/*.cpp Lab01/*.hpp)
add_executable(Lab01 ${SRC_01})

file(GLOB SRC_02 Lab02/*.cpp Lab02/*.hpp)
add_executable(Lab02 ${SRC_02})