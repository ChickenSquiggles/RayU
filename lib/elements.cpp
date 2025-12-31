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
Frame* Frame::clone()
{
    Frame* frame = new Frame(*this);
    if (frame->Parent)
    {
        frame->Parent->getChildren()->push_back(frame);
    }
    return frame;
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
    Vector2 pos = posSize.Pos;
    switch (xAllignment)
    {
        case 1:
            pos += (posSize.Size/2) - (textSize/2);
            break;
        case 2:
            pos += posSize.Size - textSize;
            break;
    }
    
    // Final Drawing
    Color finalColor = TextColor;
    finalColor.a = std::max(255 - Transparency * 25, 0.0f);

    DrawTextEx(GetFontDefault(), Text.c_str(), pos, fs, 3.0f,finalColor);
}
TextLabel* TextLabel::clone()
{
    TextLabel* textLabel = new TextLabel(*this);
    if (textLabel->Parent)
    {
        textLabel->Parent->getChildren()->push_back(textLabel);
    }
    return textLabel;
}