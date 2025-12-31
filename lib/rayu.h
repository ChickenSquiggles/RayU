#pragma once
#include "elements.h"



struct RayU 
{
    void open();
    void open(const char* title);
    void open(int width, int height);
    void open(int w, int h, const char* title, int fps);
    void open(int w, int h, const char* title, int fps, ConfigFlags flags);
    
    void pair(UiElement& element);
    void render(Color bgColor = RAYWHITE);
    
    bool isOpen();
    void close();
    
    void resizable(Udim2& from, Udim2& to);
    
    private:
    Vector2 p_startingMousePos;
    Vector2 p_startingWindowSize;
    Vector2 p_startingWindowPosition;
    bool p_isHolding;
    std::vector<UiElement*> p_Children;
};