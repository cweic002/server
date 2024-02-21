cmake_minimum_required(VERSION 3.5)

project(scoped_thread VERSION 0.1 LANGUAGES CXX)

add_library(scoped_thread
    "scoped_thread.h"
    "scoped_thread.cpp"
)

target_include_directories(scoped_thread PUBLIC ${${CMAKE_PROJECT_NAME}_SOURCE_DIR})

