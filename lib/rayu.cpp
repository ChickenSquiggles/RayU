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

void RayU::pair(UiElement* element) 
{
    p_Children.push_back(element);
}

void RayU::render(Color bgColor) 
{
    BeginDrawing();
    ClearBackground(bgColor);
    for (UiElement* child : p_Children) 
        child->render();
    EndDrawing();
}

void RayU::resizable(Udim2* within)
{
    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT))
    {
        if (!p_isHolding) {
            p_startingMousePos = GetMousePosition();
            p_startingWindowSize = Vector2
            {
                (float)GetScreenWidth(),
                (float)GetScreenHeight()
            };
            p_startingWindowPosition = GetWindowPosition();
            int lowX = std::min
            (
                p_startingWindowSize.x*within->X.Scale,
                p_startingWindowSize.x*within->X.Scale + within->X.Offset
            );
            int highX = std::max
            (
                p_startingWindowSize.x*within->X.Scale,
                p_startingWindowSize.x*within->X.Scale + within->X.Offset
            );
        
            int lowY = std::min
            (
                p_startingWindowSize.y*within->Y.Scale,
                p_startingWindowSize.y*within->Y.Scale + within->Y.Offset
            );
            int highY = std::max
            (
                p_startingWindowSize.y*within->Y.Scale,
                p_startingWindowSize.y*within->Y.Scale + within->Y.Offset
            );

            if
            (
                p_startingMousePos.x >= lowX &&
                p_startingMousePos.x <= highX &&
                p_startingMousePos.y >= lowY &&
                p_startingMousePos.y <= highY
            )
            {
                p_isHolding = true;
            }
        }
    }
    else
    {
        p_isHolding = false;
    }

    if (p_isHolding) { 
        Vector2 currentWindowPos = GetWindowPosition();
        Vector2 mousePos = GetMousePosition();
        Vector2 mouseScreen
        {
            mousePos.x + currentWindowPos.x,
            mousePos.y + currentWindowPos.y
        };
        Vector2 startingMouseScreen
        {
            p_startingMousePos.x + p_startingWindowPosition.x,
            p_startingMousePos.y + p_startingWindowPosition.y
        };

        int distX = mouseScreen.x - startingMouseScreen.x;
        int distY = mouseScreen.y - startingMouseScreen.y;
        
        bool draggingLeft = p_startingMousePos.x < p_startingWindowSize.x / 2;
        if (draggingLeft) 
        {
            int newSizeX = std::max((int)p_startingWindowSize.x - distX, 100);
            int newSizeY = std::max((int)p_startingWindowSize.y + distY, 100);
            SetWindowSize(newSizeX, newSizeY);
            SetWindowPosition(p_startingWindowPosition.x + distX, currentWindowPos.y);
        } 
        else 
        {
            int newSizeX = std::max((int)p_startingWindowSize.x + distX, 100);
            int newSizeY = std::max((int)p_startingWindowSize.y + distY, 100);
            SetWindowSize(newSizeX, newSizeY);
        }
    }
}