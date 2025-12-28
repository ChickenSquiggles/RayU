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
    Frame topBar;
    topBar.Position = Udim2::fromScale(0, 0);
    topBar.Size = Udim2::fromScale(1, .03);
    topBar.BackgroundColor = BLUE;
    ui.Pair(&topBar);

    TextLabel text;
    text.FontSize = 10;
    text.ScaleX = true;
    text.ScaleY = true;
    text.Text = "the queens bath is a very fun place";
    text.TextColor = WHITE;
    text.Position = Udim2::fromScale(0, 0);
    text.Size = Udim2::fromScale(1,1);
    text.Allignment = 0; // 0: Left, 1: Center, 2: Right
    text.parent(&topBar);
    
    int count = 0;
    while (RayU::open()) { // ui.open() also valid
        ui.Render(RAYWHITE);
    }
    

    RayU::close(); // ui.close() also valid
}