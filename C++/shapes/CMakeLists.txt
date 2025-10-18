cmake_minimum_required(VERSION 4.0)
project(Shapes)

find_package(Qt6 COMPONENTS Core Widgets)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)

add_executable(shapes
        main.cpp
        drawwindow.cpp
        drawwindow.h)
target_link_libraries(shapes Qt::Core Qt::Widgets)
