#include "rayu.h"



void makeWindow(int w, int h, const char* title, int fps) {
    InitWindow(w, h, title);
    SetTargetFPS(fps);
}

void RayU::open()
{
    makeWindow(800, 500, "RayU!", 60);
}
void RayU::open(const char* title)
{
    makeWindow(800, 500, title, 60);
}
void RayU::open(int width, int height)
{
    makeWindow(width, height, "RayU!", 60);
}
void RayU::open(int width, int height, const char* title, int fps)
{
    makeWindow(width, height, title, fps);
}
void RayU::open(int width, int height, const char* title, int fps, ConfigFlags flags)
{
    SetConfigFlags(flags);
    makeWindow(width, height, title, fps);
}


bool RayU::isOpen() 
{
    return !WindowShouldClose();
}

void RayU::close() 
{
    CloseWindow();
}

void RayU::Pair(UiElement* element) 
{
    Children.push_back(element);
}

void RayU::Render(Color bgColor) 
{
    BeginDrawing();
    ClearBackground(bgColor);
    for (UiElement* child : Children) 
        child->render();
    EndDrawing();
}