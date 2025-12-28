#pragma once
#include "elements.h"



struct RayU {
    private:
    static void makeWindow(int w, int h, const char* title, int fps);

    public:
    static bool open();
    static void close();

    std::vector<UiElement*> Children;
    void Pair(UiElement* element);

    void Render(Color bgColor = RAYWHITE);
    RayU() {
        makeWindow(800, 500,  "RayU!", 60);;
    }
    RayU(const char* title) {
        makeWindow(800, 500,  title, 60);
    }
    RayU(int w, int h) {
        makeWindow(w, h, "RayU", 60);
    }
    RayU(int w, int h, const char* title, int fps) {
        makeWindow(w, h, title, fps);
    }
    RayU(int w, int h, const char* title, int fps, ConfigFlags flag) {
        SetConfigFlags(flag);
        makeWindow(w, h, title, fps);
    }
};