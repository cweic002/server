cmake_minimum_required(VERSION 3.5)

project(socketServerLinux VERSION 0.1 LANGUAGES CXX)

add_library(socketServerLinux
    "socketServerLinux.h"
    "socketServerLinux.cpp"
)

target_link_libraries(socketServerLinux PRIVATE fSocketClientLinux)
target_include_directories(socketServerLinux PUBLIC ${${CMAKE_PROJECT_NAME}_SOURCE_DIR})

