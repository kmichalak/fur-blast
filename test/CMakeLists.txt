cmake_minimum_required(VERSION 3.0)
project(fur_blast_test)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++11")

set(FUR_BLAST_TEST_HEADERS_ROOT
        ${fur_blast_test_SOURCE_DIR}/include
        CACHE STRING "Test headers root")

set(FUR_BLAST_TEST_SOURCES_ROOT
        ${fur_blast_test_SOURCE_DIR}/src
        CACHE STRING "Test sources root")

file(GLOB FUR_BLAST_TEST_HEADERS ${FUR_BLAST_TEST_HEADERS_ROOT}/*.h)
file(GLOB FUR_BLAST_TEST_SOURCES
        ${FUR_BLAST_TEST_SOURCES_ROOT}/*.cpp)

list(REMOVE_ITEM FUR_BLAST_TEST_SOURCES ../main.cpp)



find_package(GTest REQUIRED)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_subdirectory(include)
add_subdirectory(src)

include_directories(
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${FUR_BLAST_TEST_HEADERS_ROOT}
)

add_executable(fur_blast_test
        ${FUR_BLAST_TEST_HEADERS}
        ${FUR_BLAST_TEST_SOURCES}
        ${FUR_BLAST_HEADERS}
        ${FUR_BLAST_SOURCES}
        )

target_link_libraries(
        fur_blast_test
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARY}
        ${GTEST_LIBRARY}
)