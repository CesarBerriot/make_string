include(FetchContent)

FetchContent_Declare(
  hard_assert
  GIT_REPOSITORY https://github.com/CesarBerriot/hard_assert.git
  GIT_TAG 1.0.0
)
FetchContent_Declare(
  setup_gtest
  GIT_REPOSITORY https://github.com/CesarBerriot/setup_gtest.git
  GIT_TAG 1.0.0
)

FetchContent_MakeAvailable(hard_assert setup_gtest)

include(${setup_gtest_SOURCE_DIR}/setup_gtest.cmake)