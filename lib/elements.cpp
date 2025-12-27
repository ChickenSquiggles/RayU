#include "elements.h"

void Frame::backendRender() {
    const RetVec4 posSize = getPosSize();

    if (Roundness > 0) {
        DrawRectangleRounded(
            Rectangle{
                posSize.Pos.x,
                posSize.Pos.y,
                posSize.Size.x,
                posSize.Size.y
            },
            Roundness/100,
            40,
            FillColor
        );
    } else {
        DrawRectangleRec(
            Rectangle{
                posSize.Pos.x,
                posSize.Pos.y,
                posSize.Size.x,
                posSize.Size.y
            },
            FillColor
        );
    }
}