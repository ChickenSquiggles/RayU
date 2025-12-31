#pragma once
#include <vector>
#include <string>
#include "raylib.h"

Vector2 getDimensions();
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
    Vector2 getScales();
    Vector2 getOffsets();
    Rectangle toRect();
    
    Udim X = Udim{};
    Udim Y = Udim{};
};

struct RetVec4 
{
    Vector2 Pos;
    Vector2 Size;

    Rectangle makeRect();
};

// Operator overloads of RayLib structs
Vector2 operator+(const Vector2& a, const Vector2& b);
Vector2 operator-(const Vector2& a, const Vector2& b);

Vector2 operator*(const Vector2& a, const float coefficient);
Vector2 operator*(const float coefficient, const Vector2& a);
Vector2 operator*(const Vector2& a, const Vector2& b);

Vector2 operator/(const Vector2& a, const float coefficient);
Vector2 operator/(const float coefficient, const Vector2& a);
Vector2 operator/(const Vector2& a, const Vector2& b);

Vector2& operator+=(Vector2& a, const Vector2& b);
Vector2& operator-=(Vector2& a, const Vector2& b);

Color& operator-=(Color& a, const Color& b);