#include "rayu.h"

// Properties cannot be changed after the fact. Specific functions will be implemented for changing of values
RayU ui {
    500,        // Width
    500,        // Height
    "RayU!",    // Title
    60,          // Max FPS
    FLAG_WINDOW_RESIZABLE            // Additional window flags, such as FLAG_WINDOW_UNDECORATED
};

int main() {
    Frame bluesquare;
    bluesquare.Position = Udim2::fromScale(0.5, 0.5);
    bluesquare.Size = Udim2::fromScale(0.5, 0.5);
    bluesquare.AnchorPoint = Vec2::New(0.5, 0.5);
    bluesquare.BackgroundColor = BLUE;
    ui.Pair(&bluesquare);

    TextLabel text;
    text.FontSize = 10;
    text.ScaleToFit = true;
    text.Text = "hey";
    text.TextColor = WHITE;
    text.Position = Udim2::fromScale(0, .5);
    text.Size = Udim2::fromScale(1,1);
    text.Allignment = 1; // 0: Left, 1: Center, 2: Right
    text.parent(&bluesquare);
    
    int count = 0;
    while (RayU::open()) { // ui.open() also valid
        ui.Render(RAYWHITE);
        SetWindowSize(500+(int)count*0.5, 500);
        count++;
    }
    

    RayU::close(); // ui.close() also valid
}