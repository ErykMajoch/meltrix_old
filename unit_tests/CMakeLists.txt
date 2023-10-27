Include(FetchContent)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.4.0
)

FetchContent_MakeAvailable(Catch2)

add_executable(default_initialisation default_initialisation_test.cpp)

target_link_libraries(default_initialisation PRIVATE Catch2::Catch2WithMain meltrix)

add_test(NAME default_initialisation COMMAND default_initialisation)