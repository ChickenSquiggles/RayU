#pragma once
#include <vector>
#include <cstdio>
#include "raylib.h"

struct Udim {
    float Scale;
    float Offset;
    Udim() {
        Scale = 1.0f;
        Offset = 0.0f;
    }
    Udim(float scale) {
        Scale = scale;
        Offset = 0.0f;
    }
    Udim(float scale, float offset) {
        Scale = scale;
        Offset = offset;
    }
};

struct Udim2 {
    Udim X;
    Udim Y;
    Udim2() {
        X = Udim();
        Y = Udim();
    }
    Udim2(float scale1, float scale2) {
        X = Udim(scale1);
        Y = Udim(scale2);
    }
};

struct RetVec4 {
    Vector2 Pos;
    Vector2 Size;
    RetVec4 (Vector2 pos, Vector2 size) {
        Pos = pos;
        Size = size;
    }
};