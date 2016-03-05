cmake_minimum_required(VERSION 3.3)
project(fur_blast)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)

add_executable(fur_blast ${SOURCE_FILES})