cmake_minimum_required(VERSION 3.3)
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

find_package(GTest REQUIRED)

add_subdirectory(include)
add_subdirectory(src)

include_directories(include)

add_executable(fur_blast_test
        ${FUR_BLAST_TEST_HEADERS}
        ${FUR_BLAST_TEST_SOURCES}
        )

target_link_libraries(
        fur_blast_test
        ${GTEST_LIBRARY}

)