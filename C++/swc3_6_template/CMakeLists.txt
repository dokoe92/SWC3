cmake_minimum_required(VERSION 3.16)
project(SWC3.6 VERSION 1.0.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(-Wall -Wextra -Wshadow -Wvla)

add_executable(intro intro/main.cpp)

add_executable(index index/main.cpp index/utils.cpp)

# Copy data into build-dir
file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})
