cmake_minimum_required(VERSION 3.10)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(gtest gtest.cpp)

target_link_libraries(gtest
                        src
                        ${GTEST_LIBRARIES}
                        pthread
                        )