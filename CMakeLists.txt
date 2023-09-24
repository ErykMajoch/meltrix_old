cmake_minimum_required(VERSION 3.15)
project(meltrix CXX)

add_library(meltrix src/meltrix.cpp)
target_include_directories(meltrix PUBLIC include)

set_target_properties(meltrix PROPERTIES PUBLIC_HEADER "include/meltrix.h")
install(TARGETS meltrix)
