#pragma once
#include "uielement.h"

struct Frame : UiElement 
{
    void backendRender() override;

    Color BackgroundColor = BLACK;
    float Roundness = 0;
    float Transparency = 0;

    Frame* clone();
};

struct TextLabel : UiElement
{
    void backendRender() override;
  
    Color TextColor = BLACK;
    
    std::string Text = "Hello from RayU!";
    
    float FontSize = 20;
    float Transparency = 0;
    
    int xAllignment = 0;
    int yAllignment = 0;
    
    bool AutoScaleX = false;
    bool AutoScaleY = false;

    TextLabel* clone();
};