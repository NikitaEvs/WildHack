cmake_minimum_required(VERSION 3.10)
project(peach)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)
include_directories(src/Map)
include_directories(src/util)
include_directories(src/Animals)
include_directories(thirdparty)

set (MAP_PATH src/Map)
set (UTIL_PATH src/util)
set (ANIMAL_PATH src/Animals)

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

set (ANIMAL_SOURCES
	${ANIMAL_PATH}/CarnivorePopulationBuilder.cpp
        ${ANIMAL_PATH}/HerbivorePopulationBuilder.cpp
        ${ANIMAL_PATH}/Population.cpp
        ${ANIMAL_PATH}/Population.h
        ${ANIMAL_PATH}/PopulationBuilder.h
        ${ANIMAL_PATH}/PopulationDirector.cpp
        ${ANIMAL_PATH}/PopulationDirector.h)

add_executable(example test/test.cpp ${MAP_SOURCES} ${UTIL_SOURCES} ${ANIMAL_SOURCES})
