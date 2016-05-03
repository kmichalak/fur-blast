cmake_minimum_required(VERSION 3.0)
project(fur_blast)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++11")

set(FUR_BLAST_HEADERS_ROOT ${CMAKE_SOURCE_DIR}/include CACHE STRING "Headers root")
set(FUR_BLAST_SOURCES_ROOT ${CMAKE_SOURCE_DIR}/src CACHE STRING "Sources root")

#
# Find dependency libraries.
#
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

#
# Define headers and sources directories.
#
file(GLOB FUR_BLAST_HEADERS ${FUR_BLAST_HEADERS_ROOT}/*.h)
file(GLOB FUR_BLAST_SOURCES ${FUR_BLAST_SOURCES_ROOT}/*.cpp)

#
# Copy resources to the binaries directory to make it possible to use them
# after the project is built and run.
#
file(COPY ${CMAKE_SOURCE_DIR}/img DESTINATION ${CMAKE_BINARY_DIR})

#
# Add project include directories.
#
include_directories(
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${FUR_BLAST_HEADERS_ROOT}
)

add_executable(fur_blast ${FUR_BLAST_HEADERS} ${FUR_BLAST_SOURCES} main.cpp)

#
# Link the libraries to the executable.
#
target_link_libraries(fur_blast ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})

add_subdirectory(test)