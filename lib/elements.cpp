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

void TextLabel::backendRender() {
    const RetVec4 posSize = getPosSize();
    Color finalColor = TextColor;
    finalColor.a = (Transparency > 1)?0:(255-Transparency*255);

    
    float fs = FontSize;
    if (ScaleToFit) fs = 1000;
    Vector2 textSize = MeasureTextEx(GetFontDefault(), Text.c_str(), fs, 3.0f);
    if (ScaleToFit) {
        while (textSize.x > posSize.Size.x) {
            fs -= 1;
            textSize = MeasureTextEx(GetFontDefault(), Text.c_str(), fs, 3.0f);   
        }
        while (textSize.y > posSize.Size.y) {
            fs -= 1;
            textSize = MeasureTextEx(GetFontDefault(), Text.c_str(), fs, 3.0f);   
        }
    }
    float posX = posSize.Pos.x;
    if (Allignment == 1) 
    {
        posX += (posSize.Size.x/2)-(textSize.x/2);
    } 
    else if (Allignment == 2)
    {
        posX += (posSize.Size.x)-textSize.x;
    }
    DrawTextEx(GetFontDefault(), Text.c_str(), Vector2{posX, posSize.Pos.y-(textSize.y/2)}, fs, 3.0f,finalColor);
}