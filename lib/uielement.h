#pragma once
#include "typedef.h"

struct UiElement {
    Udim2 Position;
    Udim2 Size;
    Vector2 AnchorPoint;

    std::vector<UiElement*> Children;
    UiElement *Parent = nullptr;
    virtual void parent(UiElement *p);

    virtual RetVec4 getPosSize();
    void render();
    virtual void backendRender();

    UiElement() {
        Position = Udim2(0.0f, 0.0f);
        Size = Udim2(0.5f, 0.5f);
        AnchorPoint = Vector2{0.0f, 0.0f};
    }
};