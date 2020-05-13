cmake_minimum_required(VERSION 3.10)

set (MAP_PATH Map)
set (UTIL_PATH util)
set (ANIMAL_PATH Animals)
set (ENGINE_PATH Engine)
set (MUTATION_PATH Animals/Mutations)

set (MAP_SOURCES
        ${MAP_PATH}/AbstractCellTypeBuilder.h
        ${MAP_PATH}/CellType.h
        ${MAP_PATH}/CellType.cpp
        ${MAP_PATH}/CellTypeBuilder.h
        ${MAP_PATH}/CellTypeBuilder.cpp
        ${MAP_PATH}/CellTypeDirector.h
        ${MAP_PATH}/CellTypeDirector.cpp
        ${MAP_PATH}/CellTypeJSONRepresentationBuilder.h
        ${MAP_PATH}/CellTypeJSONRepresentationBuilder.cpp
        ${MAP_PATH}/Map.h
        ${MAP_PATH}/Map.cpp
        )

set (UTIL_SOURCES
        ${UTIL_PATH}/Config.h
        ${UTIL_PATH}/Config.cpp
        ${UTIL_PATH}/RandomGenerator.h
        ${UTIL_PATH}/RandomGenerator.cpp
        )

set (ANIMAL_SOURCES
        ${ANIMAL_PATH}/CarnivorePopulationBuilder.cpp
        ${ANIMAL_PATH}/HerbivorePopulationBuilder.cpp
        ${ANIMAL_PATH}/Population.cpp
        ${ANIMAL_PATH}/Population.h
        ${ANIMAL_PATH}/PopulationBuilder.h
        ${ANIMAL_PATH}/PopulationDirector.cpp
        ${ANIMAL_PATH}/PopulationDirector.h
        )

set (ENGINE_SOURCES
        ${ENGINE_PATH}/GameEngine.h
        ${ENGINE_PATH}/GameEngine.cpp
        ${ENGINE_PATH}/Commands/Command.h
        ${ENGINE_PATH}/Commands/Command.cpp
        ${ENGINE_PATH}/Commands/MutateCommand.h
        ${ENGINE_PATH}/Commands/MutateCommand.cpp
        ${ENGINE_PATH}/Commands/SplitCommand.h
        ${ENGINE_PATH}/Commands/SplitCommand.cpp
        ${ENGINE_PATH}/Commands/MoveCommand.h
        ${ENGINE_PATH}/Commands/MoveCommand.cpp
        ${ENGINE_PATH}/Commands/StopCommand.h
        ${ENGINE_PATH}/Commands/StopCommand.cpp
        ${ENGINE_PATH}/Player/Player.h
        ${ENGINE_PATH}/Player/Player.cpp
        )

set (MUTATION_SOURCES
        ${MUTATION_PATH}/MutationComponent.h
        ${MUTATION_PATH}/LeafMutation.cpp
        ${MUTATION_PATH}/CompoundMutation.cpp
        )

add_library(src SHARED  ${MAP_SOURCES}
                        ${UTIL_SOURCES}
                        ${ANIMAL_SOURCES}
                        ${MUTATION_SOURCES}
                        ${ENGINE_SOURCES}
            )

