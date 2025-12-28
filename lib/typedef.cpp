#include "typedef.h"

Udim Udim::fromScale(float scale) 
{
    return Udim{scale, 0.0f};
};
Udim Udim::fromOffset(float offset) 
{
    return Udim{0.0f, offset};
};

Udim2 Udim2::fromScale(float xScale, float yScale) 
{
    return Udim2{xScale, 0.0f, yScale, 0.0f};
};
Udim2 Udim2::fromOffset(float xOffset, float yOffset) 
{
    return Udim2{0.0f, xOffset, 0.0f, yOffset};
};