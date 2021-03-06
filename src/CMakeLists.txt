cmake_minimum_required(VERSION 3.10)

set (MAP_PATH Map)
set (UTIL_PATH util)
set (ANIMAL_PATH Animals)
set (ENGINE_PATH Engine)
set (HANDLER_PATH Engine/Handler)
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
        ${ENGINE_PATH}/Player/Player.h
        ${ENGINE_PATH}/Player/Player.cpp
        ${ENGINE_PATH}/Manager.h
        ${ENGINE_PATH}/Manager.cpp
        ${ENGINE_PATH}/Subscriber.h
        )

set (MUTATION_SOURCES
        ${MUTATION_PATH}/MutationComponent.h
        ${MUTATION_PATH}/LeafMutation.cpp
        ${MUTATION_PATH}/CompoundMutation.cpp
        )

set (HANDLER_SOURCES
        ${HANDLER_PATH}/Handler.h
        ${HANDLER_PATH}/Handler.cpp
        ${HANDLER_PATH}/CoverMutationHandler.h
        ${HANDLER_PATH}/CoverMutationHandler.cpp
        ${HANDLER_PATH}/VelocityMutationHandler.h
        ${HANDLER_PATH}/VelocityMutationHandler.cpp
        ${HANDLER_PATH}/SafetyMutationHandler.h
        ${HANDLER_PATH}/SafetyMutationHandler.cpp
        ${HANDLER_PATH}/SizeMutationHandler.h
        ${HANDLER_PATH}/SizeMutationHandler.cpp
        ${HANDLER_PATH}/MoveHandler.h
        ${HANDLER_PATH}/MoveHandler.cpp
        )

add_library(src SHARED  ${MAP_SOURCES}
                        ${UTIL_SOURCES}
                        ${ANIMAL_SOURCES}
                        ${MUTATION_SOURCES}
                        ${ENGINE_SOURCES}
                        ${HANDLER_SOURCES}
            )

set(CMAKE_INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/lib)
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
