cmake_minimum_required(VERSION 3.10)

find_package(Qt5 COMPONENTS Widgets Qml Quick REQUIRED)

include_directories(${Qt5Widgets_INCLUDE_DIRS} ${QtQml_INCLUDE_DIRS})
include_directories(../src)

add_definitions(${Qt5Widgets_DEFINITIONS} ${QtQml_DEFINITIONS} ${${Qt5Quick_DEFINITIONS}})
qt5_add_resources(QT_RESOURCES ../resources/layout/qml.qrc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}")
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set (GUI_PATH Interface)

set (GUI_SOURCES
        ${GUI_PATH}/Gui.h
        ${GUI_PATH}/Gui.cpp
        )

project(peachGUI)

add_executable(gui execute.cpp ${QT_RESOURCES} ${GUI_SOURCES})

target_link_libraries(gui
        Qt5::Widgets
        Qt5::Qml
        Qt5::Quick
        src
        )