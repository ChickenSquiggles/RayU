#include "rayu.h"

void RayU::makeWindow(int w, int h, const char* title, int fps) {
    InitWindow(w, h, title);
    DisableEventWaiting();
    SetTargetFPS(fps);
}

bool RayU::open() {
    return !WindowShouldClose();
}

void RayU::close() {
    CloseWindow();
}

void RayU::Pair(UiElement* element) {
    Children.push_back(element);
}

void RayU::Render(Color bgColor) {
    BeginDrawing();
    ClearBackground(bgColor);
    for (UiElement* child : Children) {
        child->render();
    }
    EndDrawing();
}