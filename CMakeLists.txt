cmake_minimum_required(VERSION 3.10)

if(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE "RELEASE")
    #SET(CMAKE_BUILD_TYPE "DEBUG")
    #SET(CMAKE_BUILD_TYPE "RELWITHDEBINFO")
    #SET(CMAKE_BUILD_TYPE "MINSIZEREL")
endif()
 
project(cpp_RNG_benchmark)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES
        src/benchmark.h
        src/rngbenchmark.h
        src/main.cpp
    )

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
