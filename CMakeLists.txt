cmake_minimum_required(VERSION 3.6)
project(Socket)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Test.cpp Test.h)
add_executable(Socket ${SOURCE_FILES})