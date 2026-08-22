#include <RayU/elements.h>

void Frame::backendRender() 
{
    RetVec4 posSize = getPosSize();
    Rectangle rec = posSize.makeRect();

    Color finalColor = BackgroundColor;
    finalColor.a = std::max(255 - Transparency * 255, 0.0f);

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

void ImageLabel::backendRender()
{
    RetVec4 posSize = getPosSize();

    Rectangle sourceRec = { 0, 0, (float)Texture.width, (float)Texture.height };

    Rectangle destRec = { posSize.Pos.x, posSize.Pos.y, posSize.Size.x, posSize.Size.y };

    Vector2 origin = { 0, 0 };
    
    // draw it
    Color finalColor = WHITE;
    finalColor.a = std::max(255 - Transparency * 255, 0.0f);
    DrawTexturePro(Texture, sourceRec, destRec, origin, Rotation, finalColor);
}
void ImageLabel::setImage(std::string path)
{
    Texture = LoadTexture(path.c_str());
}

void TextLabel::backendRender() 
{
    RetVec4 posSize = getPosSize();

    // Font Size Calculation
    Vector2 baseSize = MeasureTextEx(GetFontDefault(), Text.c_str(), FontSize, 3.0f);

    float scaleX = AutoScaleX ? posSize.Size.x / baseSize.x : 1000;
    float scaleY = AutoScaleY ? posSize.Size.y / baseSize.y : 1000;
    
    float scale = std::min(scaleX, scaleY);
    float fs = (AutoScaleX || AutoScaleY) ? FontSize * scale : FontSize;

    Vector2 textSize = MeasureTextEx(GetFontDefault(), Text.c_str(), fs, 3.0f);

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
    finalColor.a = std::max(255 - Transparency * 255, 0.0f);

    DrawTextEx(GetFontDefault(), Text.c_str(), posSize.Pos, fs, 3.0f, finalColor);
}
TextLabel TextLabel::clone()
{
    TextLabel* textLabel = new TextLabel(*this);
    textLabel->Parent = nullptr;
    return *textLabel;
}