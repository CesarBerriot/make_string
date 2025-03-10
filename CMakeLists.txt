cmake_minimum_required(VERSION 3.29)
project(make_string C CXX)

include(cmake/dependencies.cmake)

add_library(make_string source/make_string.c)
target_include_directories(make_string PUBLIC include)
target_link_libraries(make_string PRIVATE hard_assert)

if(${BUILD_TESTING})
  setup_gtest(make_string)
endif()