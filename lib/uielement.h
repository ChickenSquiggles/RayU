#pragma once
#include "typedef.h"

struct UiElement {
    std::vector<UiElement*>* getChildren();
    virtual RetVec4 getPosSize();
    virtual void parent(UiElement *p);
    void render();
    
    UiElement *Parent = nullptr;
    Udim2 Position = Udim2{0.0f, 0.0f, 0.0f, 0.0f};
    Udim2 Size = Udim2{0.5f, 0.0f, 0.5f, 0.0f};
    Vector2 AnchorPoint = Vector2{0.0f, 0.0f};
    
    private:
    virtual void backendRender();
    std::vector<UiElement*> Children;
};