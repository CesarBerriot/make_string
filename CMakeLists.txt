cmake_minimum_required(VERSION 3.29)
project(make_string C)

include(FetchContent)

FetchContent_Declare(
        hard_assert
        GIT_REPOSITORY https://github.com/CesarBerriot/hard_assert.git
        GIT_TAG master
)
FetchContent_MakeAvailable(hard_assert)

add_library(make_string STATIC make_string.c)
target_include_directories(make_string PUBLIC include)
target_compile_options(make_string PRIVATE -ansi -pedantic-errors -std=c11 -Wall -Wextra)
target_link_libraries(make_string PRIVATE hard_assert)