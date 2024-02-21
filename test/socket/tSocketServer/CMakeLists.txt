cmake_minimum_required(VERSION 3.5)

project(tSocketServer VERSION 0.1 LANGUAGES CXX)

add_library(tSocketServer
    "tSocketServer.h"
    "tSocketServer.cpp"
)

target_link_libraries(tSocketServer PRIVATE tSocketClient)
target_include_directories(tSocketServer PUBLIC ${${CMAKE_PROJECT_NAME}_SOURCE_DIR})

