#pragma once
#include <vector>
#include <cstdio>
#include <string>
#include <math.h>
#include "raylib.h"
struct Udim 
{
    static Udim fromScale(float scale);
    static Udim fromOffset(float offset);
    
    float Scale = 1.0f;
    float Offset = 0.0f;
};

struct Udim2 
{
    static Udim2 fromScale(float xScale, float yScale);
    static Udim2 fromOffset(float xOffset, float yOffset);
    
    Udim X = Udim{};
    Udim Y = Udim{};
};

struct RetVec4 
{
    Vector2 Pos;
    Vector2 Size;
};