cmake_minimum_required(VERSION 3.20)
project(filesystem)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main
    main.cpp
    ls.cpp
)
