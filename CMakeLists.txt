cmake_minimum_required(VERSION 3.29)
project(make_string C CXX)

include(FetchContent)
FetchContent_Declare(
  hard_assert
  GIT_REPOSITORY https://github.com/CesarBerriot/hard_assert.git
  GIT_TAG 1.0.0
)
FetchContent_Declare(
  SetupGTest
  GIT_REPOSITORY https://github.com/CesarBerriot/SetupGTest.git
  GIT_TAG 1.0.0
)
FetchContent_MakeAvailable(hard_assert SetupGTest)

add_library(make_string source/make_string.c)
target_include_directories(make_string PUBLIC include)
target_link_libraries(make_string PRIVATE hard_assert)

if(${BUILD_TESTING})
  include(SetupGTest)
  setup_gtest(make_string)
endif()