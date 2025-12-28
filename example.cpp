#include "rayu.h"

// Properties cannot be changed after the fact. Specific functions will be implemented for changing of values
RayU ui {
    500,
    500,
    "RayU!",
    60//,
    //FLAG_WINDOW_UNDECORATED
};

int main() {
    Frame bluesquare;
    bluesquare.Position = Udim2::fromScale(0.5, 0.5);
    bluesquare.Size = Udim2::fromScale(0.5, 0.5);
    bluesquare.AnchorPoint = Vec2::New(0.5, 0.5);
    bluesquare.BackgroundColor = BLUE;
    ui.Pair(&bluesquare);

    Frame orangesquare;
    orangesquare.Position = Udim2::fromScale(0.5, 0.5);
    orangesquare.Size = Udim2::fromScale(0.5, 0.5);
    orangesquare.AnchorPoint = Vec2::New(0.5, 0.5);
    orangesquare.BackgroundColor = ORANGE;
    orangesquare.parent(&bluesquare);
    

    while (RayU::open()) { // ui.open() also valid
        ui.Render(RAYWHITE);
        orangesquare.Transparency += 0.005f;
    }
    

    RayU::close(); // ui.close() also valid
}