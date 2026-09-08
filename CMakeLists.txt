cmake_minimum_required(VERSION 3.16)

project(gc_cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(gc_cpp
    main.cpp
    src/gc.cpp
)

target_include_directories(gc_cpp PRIVATE include)

target_compile_options(gc_cpp PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)
