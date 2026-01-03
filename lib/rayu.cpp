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

void RayU::pair(UiElement& element) 
{
    p_Children.push_back(&element);
}

void RayU::render(Color bgColor) 
{
    BeginDrawing();
    ClearBackground(bgColor);
    for (UiElement* child : p_Children) 
        child->render();
    EndDrawing();
}

void RayU::resizable(Udim2 from, Udim2 to)
{
    if 
    (
        IsMouseButtonDown(MOUSE_BUTTON_LEFT)                                  && 
        CheckCollisionPointRec(GetMousePosition(), Udim2::makeRect(from, to)) && 
        !p_isResizing
    )
    {
        p_startingMousePos = GetMousePosition();
        p_startingWindowSize = getDimensions();
        p_startingWindowPosition = GetWindowPosition();
        p_isResizing = true;
    }
    
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        p_isResizing = false;

    if (!p_isResizing)
        return;

    Vector2 mousePos = GetMousePosition();
    Vector2 currentWindowPos = GetWindowPosition();

    Vector2 mouseScreen = mousePos + currentWindowPos;
    Vector2 startingMouseScreen = p_startingMousePos + p_startingWindowPosition;

    Vector2 dist = mouseScreen - startingMouseScreen;
        
    bool draggingRight = p_startingMousePos.x < p_startingWindowSize.x / 2;
    bool draggingDown = p_startingMousePos.y < p_startingWindowSize.y / 2;

    SetWindowSize( std::max( p_startingWindowSize.x + ( draggingRight ? -dist.x : dist.x ), 100.0f ), 
                   std::max( p_startingWindowSize.y + ( draggingDown  ? -dist.y : dist.y ), 100.0f ) );
    
    SetWindowPosition( p_startingWindowPosition.x + ( draggingRight ? std::min( dist.x, p_startingWindowSize.x - 100.0f ) : 0 ), 
                       p_startingWindowPosition.y + ( draggingDown  ? std::min( dist.y, p_startingWindowSize.y - 100.0f ) : 0 ) );
}

void RayU::draggable(Udim2 from, Udim2 to)
{
    Vector2 mousePos = GetMousePosition();
    Vector2 windowPos = GetWindowPosition();
    Vector2 mousePosWindow = mousePos + windowPos;
    
    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        if (CheckCollisionPointRec(mousePos, Udim2::makeRect(from, to)))
        {
            p_isDragging = true;
            p_PreviousMousePos = mousePosWindow;
        }
    
    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT))
        p_isDragging = false;

    if (!p_isDragging)
        return;
    
    Vector2 delta = mousePosWindow - p_PreviousMousePos;
    Vector2 newWindowPosition = windowPos + delta;
    SetWindowPosition( newWindowPosition.x, newWindowPosition.y );

    p_PreviousMousePos = mousePosWindow;
}