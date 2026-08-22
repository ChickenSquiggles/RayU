#pragma once
#include <RayU/elements.h>



struct RayU 
{
    void open();
    void open(const char* title);
    void open(int width, int height);
    void open(int w, int h, const char* title, int fps);
    void open(int w, int h, const char* title, int fps, ConfigFlags flags);
    
    void pair(UiElement& element);
    void unpair(UiElement& element);
    void render(Color bgColor = RAYWHITE);
    void preserveRatio(bool state);
    
    bool isOpen();
    void close();
    
    void resizable(Udim2 from, Udim2 to);
    void draggable(Udim2 from, Udim2 to);
    
    
    private:
    Vector2 p_startingMousePos;
    Vector2 p_startingWindowSize;
    Vector2 p_startingWindowPosition;
    Vector2 p_PreviousMousePos;
    double p_startingAspectRatio;
    bool p_preserveRatio = false;
    bool p_isResizing;
    bool p_isDragging;
    std::vector<UiElement*> p_Children;
};