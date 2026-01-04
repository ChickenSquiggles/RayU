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
Frame Frame::clone()
{
    Frame* frame = new Frame(*this);
    frame->Parent = nullptr;
    return *frame;
}

void TextLabel::backendRender() 
{
    RetVec4 posSize = getPosSize();
    auto measure = [&](float fs) 
    {
        return MeasureTextEx(GetFontDefault(), Text.c_str(), fs, 3.0f);
    };

    float fs = FontSize;
    Vector2 textSize = measure(fs);

    // not a huge fan of this code but i cant find a better solution
    if (AutoScaleX) 
    {
        while (textSize.x < posSize.Size.x)
        {
            fs++;
            textSize = measure(fs);
        }
        while (textSize.x > posSize.Size.x)
        {
            fs--;
            textSize = measure(fs);
        }
    }
    if (AutoScaleY) 
    {
        if (!AutoScaleX)
            while (textSize.y < posSize.Size.y) 
            {
                fs++;
                textSize = measure(fs);   
            }
        while (textSize.y > posSize.Size.y) 
        {
            fs--;
            textSize = measure(fs);   
        }
    }

    // Allignment
    if (xAllignment == 1)
        posSize.Pos.x += (posSize.Size.x / 2) - (textSize.x / 2);
    else if (xAllignment == 2)
        posSize.Pos.x += (posSize.Size.x) - textSize.x;

    if (yAllignment == 1)
        posSize.Pos.y += (posSize.Size.y / 2) - (textSize.y / 2);
    else if (yAllignment == 2)
        posSize.Pos.y += (posSize.Size.y) - textSize.y;

    // Final Drawing
    Color finalColor = TextColor;
    finalColor.a = std::max(255 - Transparency * 25, 0.0f);

    DrawTextEx(GetFontDefault(), Text.c_str(), posSize.Pos, fs, 3.0f, finalColor);
}
TextLabel TextLabel::clone()
{
    TextLabel* textLabel = new TextLabel(*this);
    textLabel->Parent = nullptr;
    return *textLabel;
}