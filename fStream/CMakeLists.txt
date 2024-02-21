cmake_minimum_required(VERSION 3.5)

project(FStream VERSION 0.1 LANGUAGES CXX)

add_library(fStream
    "fStream.h"
    "fStream.cpp"
)

target_link_libraries(fStream PUBLIC socketClientLinux)
target_include_directories(fStream PUBLIC ${${CMAKE_PROJECT_NAME}_SOURCE_DIR})

