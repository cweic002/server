cmake_minimum_required(VERSION 3.5)

project(tFSocketServer VERSION 0.1 LANGUAGES CXX)

add_library(tFSocketServer
    "tFSocketServer.h"
    "tFSocketServer.cpp"
)

target_link_libraries(tFSocketServer PUBLIC tSocketServer)
target_include_directories(tFSocketServer PUBLIC ${${CMAKE_PROJECT_NAME}_SOURCE_DIR})

