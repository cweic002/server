cmake_minimum_required(VERSION 3.5)

project(tSocketClient VERSION 0.1 LANGUAGES CXX)

add_library(tSocketClient
    "tSocketClient.h"
    "tSocketClient.cpp"
)

target_include_directories(tSocketClient PUBLIC ${${CMAKE_PROJECT_NAME}_SOURCE_DIR})

