#pragma once
#include "elements.h"



struct RayU 
{
    void open();
    void open(const char* title);
    void open(int width, int height);
    void open(int w, int h, const char* title, int fps);
    void open(int w, int h, const char* title, int fps, ConfigFlags flags);
    
    void Pair(UiElement* element);
    void Render(Color bgColor = RAYWHITE);
    
    bool isOpen();
    void close();
    
    private:
    std::vector<UiElement*> Children;
};