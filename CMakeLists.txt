cmake_minimum_required(VERSION 3.10)
project(peach)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(src/Map)
include_directories(src/util)
include_directories(src/Animals)
include_directories(thirdparty)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(src)

add_subdirectory(gui)

add_executable(example test/test.cpp)
target_link_libraries(example src)
