cmake_minimum_required(VERSION 3.20)

project(str LANGUAGES C)
set(CMAKE_C_STANDARD 23)

set(SOURCES str.c main.c)
set(HEADERS str.h)

add_executable(str 
    ${SOURCES}
    ${HEADERS})
target_compile_options(str PUBLIC
    -Wall -Wextra -Werror -Wpedantic
)
