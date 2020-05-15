cmake_minimum_required(VERSION 3.10)
project(peach)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(src/Map)
include_directories(src/util)
include_directories(src/Animals)
include_directories(gui)
include_directories(gui/Interface)
include_directories(thirdparty)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)


add_subdirectory(src)

if (GUI_BUILD)
    add_subdirectory(gui)
endif (GUI_BUILD)

if (TEST_BUILD)
    add_subdirectory(test/unit)
endif(TEST_BUILD)

add_executable(example test/test.cpp)
target_link_libraries(example src)
