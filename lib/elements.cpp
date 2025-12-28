#include "elements.h"

void Frame::backendRender() {
    const RetVec4 posSize = getPosSize();
    Color finalColor = BackgroundColor;
    finalColor.a = (Transparency > 1)?0:(255-Transparency*255);

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
            finalColor
        );
    } else {
        DrawRectangleRec(
            Rectangle{
                posSize.Pos.x,
                posSize.Pos.y,
                posSize.Size.x,
                posSize.Size.y
            },
            finalColor
        );
    }
}