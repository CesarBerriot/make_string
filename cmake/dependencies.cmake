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

include(SetupGTest)