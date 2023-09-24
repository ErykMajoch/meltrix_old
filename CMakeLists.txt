cmake_minimum_required(VERSION 3.15)
project(meltrix VERSION 0.0 DESCRIPTION "A Simple Matrix Library Written in C++" LANGUAGES CXX)

add_library(meltrix src/meltrix.cpp)
target_include_directories(meltrix PUBLIC include)

set_target_properties(meltrix PROPERTIES PUBLIC_HEADER "include/meltrix.h")
install(TARGETS meltrix)
