cmake_minimum_required(VERSION 3.10)

project(code_cpp_RNG_benchmark)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        src/benchmark.h
        src/main.cpp
    )

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
