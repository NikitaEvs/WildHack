cmake_minimum_required(VERSION 3.15)
project(peach)

set(CMAKE_CXX_STANDARD 17)

include_directories(src/Animals)

add_executable(peach
        src/Animals/CarnivorePopulationBuilder.cpp
        src/Animals/HerbivorePopulationBuilder.cpp
        src/Animals/Population.cpp
        src/Animals/Population.h
        src/Animals/PopulationBuilder.h
        src/Animals/PopulationDirector.cpp
        src/Animals/PopulationDirector.h
        test.cpp)
