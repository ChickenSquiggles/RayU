#pragma once
#include "typedef.h"

struct UiElement {
    std::vector<UiElement*>* getChildren();
    virtual RetVec4 getPosSize();
    virtual void parent(std::optional<std::reference_wrapper<UiElement>> p);
    std::function<void()> onClick;
    std::function<void()> onHoverStart;
    std::function<void()> onHoverEnd;
    void render();
    bool forceCalculation = false;
    bool hovering = false;
    bool clickmem = false;
    
    UiElement *Parent = nullptr;
    Udim2 Position = Udim2{0.0f, 0.0f, 0.0f, 0.0f};
    Udim2 Size = Udim2{0.5f, 0.0f, 0.5f, 0.0f};
    Vector2 AnchorPoint = Vector2{0.0f, 0.0f};
    
    std::vector<UiElement*> Children;
    private:
    virtual void backendRender();
};