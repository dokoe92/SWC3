Makefile starte:
mingw32-make


CMake:
cmake -G "MinGW Makefiles"
cmake -G "MinGW Makefiles" -B build

mit -G Generator auswählen
mit -B build wird in build reingegeben

mit cmake --build build wird dann aus dem build ordner das exe gebaut


cmake_minimum_required(VERSION 3.20)

project(str LANGUAGES C)

add_executable(str 
    main.c str.c str.h)

kann man mit set variablen machen auch