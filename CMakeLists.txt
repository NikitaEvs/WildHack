cmake_minimum_required(VERSION 3.15)

project(peach)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(src/Map)
include_directories(src/util)
include_directories(thirdparty)

set (MAP_PATH src/Map)
set (UTIL_PATH src/util)

set (MAP_SOURCES
        ${MAP_PATH}/AbstractCellBuilder.h
        ${MAP_PATH}/Cell.h
        ${MAP_PATH}/Cell.cpp
        ${MAP_PATH}/CellBuilder.h
        ${MAP_PATH}/CellBuilder.cpp
        ${MAP_PATH}/CellDirector.h
        ${MAP_PATH}/CellDirector.cpp
        ${MAP_PATH}/CellJSONRepresentationBuilder.h
        ${MAP_PATH}/CellJSONRepresentationBuilder.cpp
        )

set (UTIL_SOURCES
        ${UTIL_PATH}/Config.h
        ${UTIL_PATH}/Config.cpp
        ${UTIL_PATH}/Random.h
        ${UTIL_PATH}/Random.cpp
        )

add_executable(test test/test.cpp ${MAP_SOURCES} ${UTIL_SOURCES})