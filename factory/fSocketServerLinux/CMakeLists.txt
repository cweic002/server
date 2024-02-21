cmake_minimum_required(VERSION 3.5)

project(fSocketServerLinux VERSION 0.1 LANGUAGES CXX)

add_library(fSocketServerLinux
    "fSocketServerLinux.h"
    "fSocketServerLinux.cpp"
)

target_link_libraries(fSocketServerLinux PUBLIC socketServerLinux)
target_include_directories(fSocketServerLinux PUBLIC ${${CMAKE_PROJECT_NAME}_SOURCE_DIR})

