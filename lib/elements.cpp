#include "elements.h"

void Frame::backendRender() 
{
    RetVec4 posSize = getPosSize();
    Rectangle rec = posSize.makeRect();

    Color finalColor = BackgroundColor;
    finalColor.a = std::max(255 - Transparency * 25, 0.0f);

    DrawRectangleRounded
    (
        rec,
        Roundness/100,
        40,
        finalColor
    );
}

void TextLabel::backendRender() 
{
    const RetVec4 posSize = getPosSize();
    auto measure = [&](float fs) 
    {
        return MeasureTextEx(GetFontDefault(), Text.c_str(), fs, 3.0f);
    };

    float fs = FontSize;
    Vector2 textSize = measure(fs);

    // Auto Scaling (i know this code sucks i need to go back and change it)
    if (AutoScaleX) 
    {
        if (textSize.x < posSize.Size.x)
        {
            while (textSize.x < posSize.Size.x)
            {
                fs++;
                textSize = measure(fs);
            }
            fs--;
        }
        else
        {
            while (textSize.x > posSize.Size.x)
            {
                fs--;
                textSize = measure(fs);
            }
        }
    }
    if (AutoScaleY) 
    {
        if (!AutoScaleX) 
        {
            while (textSize.x < posSize.Size.x)
            {
                fs++;
                textSize = measure(fs);
            }
            fs--;
        }
        while (textSize.y > posSize.Size.y) 
        {
            fs--;
            textSize = measure(fs);   
        }
    }

    // Allignment
    float posX = posSize.Pos.x;
    if (xAllignment == 1)
        posX += (posSize.Size.x/2)-(textSize.x/2);
    else if (xAllignment == 2)
        posX += (posSize.Size.x)-textSize.x;

    float posY = posSize.Pos.y;
    if (yAllignment == 1)
        posY += (posSize.Size.y/2)-(textSize.y/2);
    else if (yAllignment == 2)
        posY += (posSize.Size.y)-textSize.y;
    
    
    // Final Drawing
    Color finalColor = TextColor;
    finalColor.a = (Transparency > 1)
    ? 0
    : (255-Transparency*255);

    DrawTextEx(GetFontDefault(), Text.c_str(), Vector2{posX, posY}, fs, 3.0f,finalColor);
}