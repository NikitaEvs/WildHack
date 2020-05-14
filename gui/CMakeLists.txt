cmake_minimum_required(VERSION 3.10)

find_package(Qt5 COMPONENTS Widgets Qml Quick Core REQUIRED)

include_directories(${Qt5Widgets_INCLUDE_DIRS} ${QtQml_INCLUDE_DIRS})
include_directories(../src)

add_definitions(${Qt5Widgets_DEFINITIONS} ${QtQml_DEFINITIONS} ${${Qt5Quick_DEFINITIONS}})
qt5_add_resources(QT_RESOURCES ../resources/layout/qml.qrc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set (GUI_PATH Interface)
set (ENGINE_PATH Interface)

set (GUI_SOURCES
        ${GUI_PATH}/Gui.h
        ${GUI_PATH}/Gui.cpp
        )

set (COMMAND_SOURCES
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
        )

project(peachGUI)

add_executable(gui execute.cpp  ${QT_RESOURCES}
                                ${GUI_SOURCES}
                                ${COMMAND_SOURCES})

if (GUI_TEST_BUILD)
    add_subdirectory(thirdparty/spix)

    include_directories(Interface)
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
    set(CMAKE_AUTOMOC ON)
    set(CMAKE_AUTORCC ON)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)

    find_package(Qt5 COMPONENTS Core Quick REQUIRED)
    find_package(GTest REQUIRED)

    add_executable(gui_test Test/guiTest.cpp "../resources/layout/qml.qrc" ${GUI_SOURCES})
    target_compile_definitions(gui_test PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)
    target_link_libraries(gui_test PRIVATE Qt5::Widgets Qt5::Qml Qt5::Core Qt5::Quick GTest::GTest Spix src)
endif(GUI_TEST_BUILD)

target_link_libraries(gui
        Qt5::Widgets
        Qt5::Qml
        Qt5::Quick
        src
        )