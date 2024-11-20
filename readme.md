```cmake
    include(FetchContent)

    FetchContent_Declare(
        make_string
        GIT_REPOSITORY https://github.com/CesarBerriot/make_string.git
        GIT_TAG master
    )
    FetchContent_MakeAvailable(make_string)

    target_link_libraries(PROJECT_NAME PRIVATE make_string)
```