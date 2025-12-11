cmake_minimum_required(VERSION 3.16)
project(SWC3.5 VERSION 1.0.0 LANGUAGES C CXX)

# configure C17
set(CMAKE_C_STANDARD 17)          # request C17
set(CMAKE_C_STANDARD_REQUIRED ON) # enforce requested standard
set(CMAKE_C_EXTENSIONS OFF)       # disable compiler specific extensions

# configure C++23
set(CMAKE_CXX_STANDARD 23)          # request C++23
set(CMAKE_CXX_STANDARD_REQUIRED ON) # enforce requested standard
set(CMAKE_CXX_EXTENSIONS OFF)       # disable compiler specific extensions

# --- Common compiler warnings ---
set(COMMON_WARNINGS
        -Wall
        -Wextra
        -Wpedantic
        -Wconversion
        -Werror=vla
)

# --- Targets ---
add_executable(templates
        src/main_templates.cpp
)
target_compile_options(templates PRIVATE ${COMMON_WARNINGS})

add_executable(vector
        src/main_vector.cpp
)
target_compile_options(templates PRIVATE ${COMMON_WARNINGS})
