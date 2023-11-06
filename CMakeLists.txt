cmake_minimum_required(VERSION 3.15)
project(meltrix VERSION 0.1.1 DESCRIPTION "A Simple Matrix Library Written in C++" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(CODE_COVERAGE "Enable coverage reporting" ON)

if(CODE_COVERAGE AND CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    message("Building with code coverage")
    set(CMAKE_BUILD_TYPE Debug)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
    set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

enable_testing()

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(unit_tests)

add_library("${PROJECT_NAME}" ${SOURCE_LIST})
target_include_directories("${PROJECT_NAME}" PUBLIC include)
set_target_properties("${PROJECT_NAME}" PROPERTIES PUBLIC_HEADER "${HEADER_LIST}")
set_target_properties("${PROJECT_NAME}" PROPERTIES VERSION ${LIBRARY_VERSION})

install(TARGETS "${PROJECT_NAME}")
