cmake_minimum_required(VERSION 3.15)
project(meltrix VERSION 0.0.1 DESCRIPTION "A Simple Matrix Library Written in C++" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(include)
add_subdirectory(src)

add_library("${PROJECT_NAME}" ${SOURCE_LIST} )
target_include_directories("${PROJECT_NAME}" PUBLIC include)
set_target_properties("${PROJECT_NAME}" PROPERTIES PUBLIC_HEADER "${HEADER_LIST}")

install(TARGETS "${PROJECT_NAME}")
