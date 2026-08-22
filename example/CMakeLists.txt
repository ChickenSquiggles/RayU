# LINES 1-12 ONLY WORK IN THIS ENVIRONMENT. To use RayU as a library, refer to the commented section lines 17 and onwards.

add_executable(RayUExample
    example.cpp
)

target_link_libraries(RayUExample
    PRIVATE
        RayU::RayU
)

target_compile_features(RayUExample PRIVATE cxx_std_20)


# Example CMakeLists.txt for a standalone project using RayU

#[[
    cmake_minimum_required(VERSION 3.29)
    project(app LANGUAGES CXX)
    
    include(FetchContent)
    
    FetchContent_Declare(
        RayU
        GIT_REPOSITORY https://github.com/ChickenSquiggles/RayU.git
        GIT_TAG v1.0.0
    )
    
    FetchContent_MakeAvailable(RayU)
    
    add_executable(app example.cpp)
    
    target_link_libraries(app RayU)
]]