#include "rayu.h"

RayU ui;

int main() 
{
    Frame topBar;
    topBar.Position = Udim2::fromScale(0, 0);
    topBar.Size = Udim2{1, 0, 0, 25};
    topBar.BackgroundColor = BLACK;
    ui.Pair(&topBar);

    TextLabel text;
    text.FontSize = 10;
    text.AutoScaleX = false;
    text.AutoScaleY = true;
    text.Text = "blah blah";
    text.TextColor = WHITE;
    text.Position = Udim2::fromScale(0, 0);
    text.Size = Udim2::fromScale(1,1);
    text.xAllignment = 1; // 0: Left, 1: Center, 2: Right
    text.yAllignment = 2; // 0: Top, 1: Center, 2: Bottom
    text.parent(&topBar);
    
    int count = 0;

    ui.open(800, 500, "Hello!", 60, FLAG_WINDOW_RESIZABLE);
    while (ui.isOpen()) 
    {
        ui.Render(RAYWHITE);
    }
    ui.close();
}