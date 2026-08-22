cmake_minimum_required(VERSION 3.29)

project(RayU
    VERSION 1.0.0
    LANGUAGES CXX
)

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.0
)

FetchContent_MakeAvailable(raylib)

add_library(RayU
    src/elements.cpp
    src/rayu.cpp
    src/typedef.cpp
    src/uielement.cpp
)

target_include_directories(RayU
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(RayU PUBLIC cxx_std_20)

target_link_libraries(RayU
    PUBLIC
        raylib
)

add_library(RayU::RayU ALIAS RayU)

# Uncomment the line below to compile the example housed in the "example" folder
# add_subdirectory(example)