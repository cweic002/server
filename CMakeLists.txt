cmake_minimum_required(VERSION 3.5)

project(serverApp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${CMAKE_PROJECT_NAME}
    "main.cpp"
)

add_subdirectory(socket)
add_subdirectory(factory)
add_subdirectory(fStream)
add_subdirectory(thread)
add_subdirectory(test)

target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC fSocketServerLinux)
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC tFSocketServer)
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC fStream)
target_link_libraries(${CMAKE_PROJECT_NAME} PUBLIC scoped_thread)

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS ${CMAKE_PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
