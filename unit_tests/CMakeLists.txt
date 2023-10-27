find_package(Catch2 3 REQUIRED)
add_executable(test1 test.cpp)
target_link_libraries(test1 PRIVATE Catch2::Catch2WithMain)
add_test(NAME test1 COMMAND test1)