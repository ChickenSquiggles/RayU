#include "rayu.h"

RayU ui;

int main() 
{
    // Make frame (sqaure that is able to be rounded)
    Frame square;
    // Set its position to half its parent's (which without a parent is the ui/whole window)
    square.Position = Udim2::fromScale(0.5, 0.5);
    // Same idea for the size
    square.Size = Udim2::fromScale(0.5, 0.5);
    // Anchor around the center of the square
    square.AnchorPoint = Vector2{0.5, 0.5};
    // Make the color black
    square.BackgroundColor = BLACK;
    /* Pair it to the UI. At least one item needs to be paired to the UI for the tree to be rendered, but you can have
       as many as you want paired to the UI. Though, any children of an item will be rendered too. */ 
    ui.pair(square);


    // Make a new square, but this time make it a clone of the first. This simply takes all of the properties of the one cloned.
    Frame* square2 = square.clone();
    // Parent this new one to the old one
    square2->parent(square);
    // Change the color up
    square2->BackgroundColor = WHITE;

    // This results in a centered black square with half of the windows dimensions, with a white square inside of it taking half of its parents dimensions (inheritely 1/4 of the window)

    

    
    // Be able to drag from the bottom right corner
    Udim2 dragTo = Udim2::fromScale(1, 1);
    // took the ending point and went back 30 pixels on x and y. you could change the scales arounds too but i think pixels make sense for dragging.
    Udim2 dragFrom = dragTo - Udim2::fromOffset(30, 30);

    ui.open(800, 500, "Hello!", 60, FLAG_WINDOW_UNDECORATED);
    while (ui.isOpen()) 
    {
        ui.resizable(dragFrom, dragTo);
        ui.render(RAYWHITE);
    }
    ui.close();
}




















/* Example 1
    Frame topBar;
    topBar.Position = Udim2::fromScale(0, 0);
    topBar.Size = Udim2{1, 0, 0, 25};
    topBar.BackgroundColor = BLACK;
    ui.pair(topBar);
    TextLabel text;
    text.FontSize = 10;
    text.AutoScaleX = true;
    text.AutoScaleY = true;
    text.Text = "blah blah";
    text.TextColor = WHITE;
    text.Position = Udim2::fromScale(0, 0);
    text.Size = Udim2::fromScale(1,1);
    text.xAllignment = 1; // 0: Left, 1: Center, 2: Right
    text.yAllignment = 2; // 0: Top, 1: Center, 2: Bottom
    text.parent(topBar);

    // be able to resize from 30 pixels inset from top left corner. not sure why youd do that but its possible now :) 
    Udim2 dragFrom = Udim2::fromScale(0.0f, 0.0f);
    Udim2 dragTo = Udim2::fromOffset(30.0f, 30.0f);
*/