#include "rayu.h"


int main() {
    SetConfigFlags(FLAG_WINDOW_UNDECORATED);
    RayU ui {
        500,
        500,
        "macro!",
        60
    };
    
    Frame test;
    test.Position = Udim2(0.5, 0.5);
    test.Size = Udim2(0.5, 0.5);
    test.AnchorPoint = Vector2(0.5, 0.5);
    test.FillColor = BLUE;
    test.Roundness = 0;

    ui.Pair(&test);

    while (ui.open()) {
        ui.Render(RAYWHITE);
    }
    

    ui.close();
}