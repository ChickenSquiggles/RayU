#pragma once
#include "uielement.h"

struct Frame : UiElement {
    Color FillColor;
    float Roundness;
    void backendRender() override;
    Frame() {
        FillColor = Color{0, 0, 0, 255};
        Roundness = 0;
    }
    Frame(float PosScaleX, float PosScaleY, float SizeScaleX, float SizeScaleY) {
        Position = Udim2(PosScaleX, PosScaleY);
        Size = Udim2(SizeScaleX, SizeScaleY);
    }
    Frame(float PosScaleX, float PosScaleY, float SizeScaleX, float SizeScaleY, float AnchorPointX, float AnchorPointY) {
        Position = Udim2(PosScaleX, PosScaleY);
        Size = Udim2(SizeScaleX, SizeScaleY);
        AnchorPoint = Vector2(AnchorPointX, AnchorPointY);
    }
};


struct Canvas : UiElement {
    
};