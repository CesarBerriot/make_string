cmake_minimum_required(VERSION 3.29)
project(make_string C)

include(FetchContent)

FetchContent_Declare(
        hard_assert
        GIT_REPOSITORY https://github.com/CesarBerriot/hard_assert.git
        GIT_TAG 1.0.0
)
FetchContent_MakeAvailable(hard_assert)

add_library(make_string source/make_string.c)
target_include_directories(make_string PUBLIC include)
target_link_libraries(make_string PRIVATE hard_assert)
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(make_string PRIVATE -ansi -pedantic-errors -std=c11 -Wall -Wextra)
endif()