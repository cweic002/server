cmake_minimum_required(VERSION 3.5)

project(thread_guard VERSION 0.1 LANGUAGES CXX)

add_library(thread_guard
    "thread_guard.h"
    "thread_guard.cpp"
)

target_include_directories(thread_guard PUBLIC ${${CMAKE_PROJECT_NAME}_SOURCE_DIR})

