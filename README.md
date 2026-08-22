# RayU - WIP

**Hierarchical UI Abstraction for Raylib**

RayU is a UI abstraction layer built on top of Raylib that replaces direct pixel-based drawing with an object-driven layout system similar to Roblox. Instead of rendering directly to the window, you create UI objects that support:

- Parent–child relationships  
- Inherited size and position  
- Resolution-independent scaling  

Objects can define their size and position as either:

- Scale factors relative to their parent, or  
- Explicit pixel values when needed

This allows interfaces to remain **uniform across any monitor or window size**, without hard pixel dependencies.

This is mostly for my own learning so don't expect it to be the greatest project ever.

<br><br>
Here is a program that was made using RayU. (Framerate Lowered Due To Being A Gif)

![Example Program Made With RayU](https://i.ibb.co/vx7cND5P/example.gif)

<br><br>
Example CMake Usage Of RayU (refer to example/example.cpp for a code example)
```
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
```