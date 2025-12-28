#pragma once
#include "uielement.h"

struct Frame : UiElement {
    Color BackgroundColor;
    float Roundness;
    float Transparency;
    void backendRender() override;
    Frame() {
        BackgroundColor = Color{0, 0, 0, 255};
        Transparency = 0;
        Roundness = 0;
    }
    Frame(float PosScaleX, float PosScaleY, float SizeScaleX, float SizeScaleY) {
        Position = Udim2::fromScale(PosScaleX, PosScaleY);
        Size = Udim2::fromScale(SizeScaleX, SizeScaleY);
    }
    Frame(float PosScaleX, float PosScaleY, float SizeScaleX, float SizeScaleY, float AnchorPointX, float AnchorPointY) {
        Position = Udim2::fromScale(PosScaleX, PosScaleY);
        Size = Udim2::fromScale(SizeScaleX, SizeScaleY);
        AnchorPoint = Vec2::New(AnchorPointX, AnchorPointY);
    }
};


struct TextLabel : UiElement {
    std::string Text;
    Color TextColor;
    float FontSize;
    bool ScaleX;
    bool ScaleY;
    float Transparency;
    int Allignment;
    void backendRender() override;
    TextLabel() {
        TextColor = Color{0,0,0,255};
        FontSize = 12;
        ScaleX = false;
        ScaleY = false;
        Transparency = 0;
    }
};