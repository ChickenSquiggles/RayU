#include "typedef.h"

Vec2 Vec2::New(float x, float y) {
    return Vec2{
        x,
        y
    };
}


Udim Udim::New(float scale, float offset) {
    return Udim{
        scale, 
        offset
    };
}
Udim Udim::fromScale(float scale) {
    return Udim{
        Udim::New(
            scale,
            0.0f
        )
    };
};
Udim Udim::fromOffset(float offset) {
    return Udim{
        Udim::New(
            0.0f,
            offset
        )
    };
};


Udim2 Udim2::New(float xScale, float xOffset, float yScale, float yOffset) {
    return Udim2{
        Udim::New(
            xScale,
            xOffset
        ),
        Udim::New(
            yScale,
            yOffset
        )
    };
}
Udim2 Udim2::fromScale(float xScale, float yScale) {
    return Udim2{
        Udim::New(
            xScale,
            0.0f
        ),
        Udim::New(
            yScale,
            0.0f
        )
    };
};
Udim2 Udim2::fromOffset(float xOffset, float yOffset) {
    return Udim2{
        Udim::New(
            0.0f,
            xOffset
        ),
        Udim::New(
            0.0f,
            yOffset
        )
    };
};