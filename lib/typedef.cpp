#include "typedef.h"

Vector2 getDimensions()
{
    return { static_cast<float>(GetScreenWidth() ),
             static_cast<float>(GetScreenHeight()) };
}

// UDIM
Udim Udim::fromScale(float scale) 
{
    return Udim{ scale, 0.0f };
}
Udim Udim::fromOffset(float offset) 
{
    return Udim{ 0.0f, offset };
}

// UDIM2
Udim2 Udim2::fromScale(float xScale, float yScale) 
{
    return Udim2{ xScale, 
                  0.0f, 
                  yScale, 
                  0.0f};
}
Udim2 Udim2::fromOffset(float xOffset, float yOffset) 
{
    return Udim2{ 0.0f, 
                  xOffset, 
                  0.0f, 
                  yOffset};
}
Vector2 Udim2::getScales()
{
    return { this->X.Scale, this->Y.Scale };
}
Vector2 Udim2::getOffsets()
{
    return { this->X.Offset, this->Y.Offset };
}
Rectangle Udim2::makeRect(const Udim2& from, const Udim2& to)
{
    Vector2 size = getDimensions();
    Rectangle result;
    result.x = from.X.Scale * size.x + from.X.Offset;
    result.y = from.Y.Scale * size.y + from.Y.Offset;
    result.width =  (to.X.Scale * size.x + to.X.Offset) - result.x;
    result.height = (to.Y.Scale * size.y + to.Y.Offset) - result.y;

    return result;
}

Udim2 operator+(const Udim2& a, const Udim2& b)
{
    return Udim2 { a.X.Scale  + b.X.Scale,
                   a.X.Offset + b.X.Offset,
                   a.Y.Scale  + b.Y.Scale,
                   a.Y.Offset + b.Y.Offset };
}
Udim2 operator-(const Udim2& a, const Udim2& b)
{
    return Udim2 { a.X.Scale  - b.X.Scale,
                   a.X.Offset - b.X.Offset,
                   a.Y.Scale  - b.Y.Scale,
                   a.Y.Offset - b.Y.Offset };
}

// RETVEC4
Rectangle RetVec4::makeRect()
{
    return { Pos.x, 
             Pos.y, 
             Size.x, 
             Size.y };
}

// VECTOR2 (RAYLIB)
Vector2 operator+(const Vector2& a, const Vector2& b)
{
    return { a.x + b.x, 
             a.y + b.y };
}
Vector2 operator-(const Vector2& a, const Vector2& b)
{
    return { a.x - b.x, 
             a.y - b.y };
}
Vector2 operator*(const Vector2& a, const float coefficient)
{
    return { a.x * coefficient,
             a.y * coefficient };
}
Vector2 operator*(const float coefficient, const Vector2& a)
{
    return a * coefficient;
}
Vector2 operator*(const Vector2& a, const Vector2& b)
{
    return { a.x * b.x,
             a.y * b.y };
}

Vector2 operator/(const Vector2& a, const float coefficient)
{
    return { a.x / coefficient,
             a.y / coefficient };
}
Vector2 operator/(const float coefficient, const Vector2& a)
{
    return a / coefficient;
}
Vector2 operator/(const Vector2& a, const Vector2& b)
{
    return { a.x / b.x,
             a.y / b.y };
}

Vector2& operator+=(Vector2& a, const Vector2& b)
{
    a.x += b.x;
    a.y += b.y;
    return a;
}
Vector2& operator-=(Vector2& a, const Vector2& b)
{
    a.x -= b.x;
    a.y -= b.y;
    return a;
}
Color& operator-=(Color& a, const Color& b)
{
    a.r = std::max(a.r - b.r, 0);
    a.g = std::max(a.g - b.g, 0);
    a.b = std::max(a.b - b.b, 0);
    a.a = std::max(a.a - b.a, 0);

    return a;
}