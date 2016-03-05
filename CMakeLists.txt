cmake_minimum_required(VERSION 3.3)
project(fur_blast)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++11")

set(FUR_BLAST_HEADERS_ROOT ${CMAKE_SOURCE_DIR}/include CACHE STRING "Headers root")
set(FUR_BLAST_SOURCES_ROOT ${CMAKE_SOURCE_DIR}/src CACHE STRING "Sources root")

find_package(SDL2 REQUIRED)

file(GLOB FUR_BLAST_HEADERS ${FUR_BLAST_HEADERS_ROOT}/*.h)
file(GLOB FUR_BLAST_SOURCES main.cpp ${FUR_BLAST_SOURCES_ROOT}/*.cpp)

include_directories(
        ${SDL2_INCLUDE_DIR}
        ${FUR_BLAST_HEADERS_ROOT}
)

add_executable(fur_blast ${FUR_BLAST_HEADERS} ${FUR_BLAST_SOURCES})

target_link_libraries(fur_blast ${SDL2_LIBRARY})