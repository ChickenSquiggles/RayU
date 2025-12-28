#pragma once
#include <vector>
#include <cstdio>
#include <string>
#include "raylib.h"

struct Vec2 {
    float x;
    float y;

    static Vec2 New(float x, float y);
};

struct Udim {
    float Scale;
    float Offset = 0;
    static Udim New(float scale, float offset);
    static Udim fromScale(float scale);
    static Udim fromOffset(float offset);
};

struct Udim2 {
    Udim X;
    Udim Y;

    static Udim2 New(float xScale, float xOffset, float yScale, float yOffset);
    static Udim2 fromScale(float xScale, float yScale);
    static Udim2 fromOffset(float xOffset, float yOffset);
};

struct RetVec4 {
    Vec2 Pos;
    Vec2 Size;
};