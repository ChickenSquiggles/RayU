#include "rayu.h"

RayU ui;

// Udim2 consists of X, Y, two Udim2's. 

int main() 
{
    // Lets start off with a top bar to drag from
    Frame topBar;
    // Position will always start at 0,0 unless changed so we dont have to touch it
    // Make the size inherit all of the parent's (window's) x size, and 8% of the parent's y size.
    topBar.Size = Udim2::fromScale(1, 0.08);
    topBar.BackgroundColor = BLACK;
    /* Pair it to the UI. At least one item needs to be paired to the UI for the tree to be rendered, but you can have
       as many as you want paired to the UI. Though, any children of an item will be rendered too. */ 
    ui.pair(topBar);

    // Some dimensions for how to drag our window. We will use this in the render loop. 
    // You can always make the window decorated to not have to manually handle dragging, but i prefer the look of a custom undecorated window.
        // Top left corner.
    Udim2 dragFrom = Udim2::fromScale(0, 0);
        // Top right corner, down 8% just like our bar.
    Udim2 dragTo = Udim2::fromScale(1, .08);

    // Now for some text
    TextLabel topBarText;
    topBarText.Text = "This is a draggable bar!";
    topBarText.TextColor = WHITE;
    // Make it a lil bit smaller than the parent to make it look cleaner. optional
    topBarText.Size = Udim2::fromScale(1, .8);
    // Move it down a lil to compensate for it being smaller. also optional
    topBarText.Position = Udim2::fromScale(0, .1);
    // Let RayU handle the font size. Recommended
    topBarText.AutoScaleX = true;
    topBarText.AutoScaleY = true;
    // Center on x and y
    topBarText.xAllignment = 1;
    topBarText.yAllignment = 1;

    // Parent it to the topbar so RayU knows how and where to render it.
    topBarText.parent(topBar);


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
    // Pair it.
    ui.pair(square);


    // Make a new square, but this time make it a clone of the first. This simply takes all of the properties of the one cloned.
    Frame square2 = square.clone();
    // Change the color
    square2.BackgroundColor = WHITE;
    // Might as well make it round (roundness 0-100 like percents)
    square2.Roundness = 100;
    // Parent this new one to the old one. Parent is not inherited with clone.
    square2.parent(square);

    
    // Lets make some text in the middle
    TextLabel text;
    text.Text = "hey!";
    text.TextColor = BLACK; // black is already default. just showing how it works
    // Scale both the x and y automatically so it fits in the circle well, and lets center it on x and y
    text.AutoScaleX = true;
    text.xAllignment = 1;
    text.AutoScaleY = true;
    text.yAllignment = 1;
    // Inherit 70% of size from the parent to make up for the rounded edegs (magic number), and center the textlabel around the center of the parent
    text.Position = Udim2::fromScale(.5, .5);
    text.AnchorPoint = Vector2{.5, .5};
    text.Size = Udim2::fromScale(.7, .7);
    // Of course, we have to parent it to something. In this case, we should parent it to the inner square/circle thing we made
    text.parent(square2);

    
    // Be able to drag from the bottom right corner
    Udim2 dragToResize = Udim2::fromScale(1, 1);
    // took the ending point and went back 30 pixels on x and y. you could change the scales arounds too but i think pixels make sense for dragging.
    Udim2 dragFromResize = dragToResize - Udim2::fromOffset(30, 30);

    
    // Finally we can open our window. You can do this at any point, as long as its before rendering.
    // X, Y, Title, FPS, Flags. Has overloads, check rayu.cpp.
    ui.open(800, 500, "Hello!", 60, FLAG_WINDOW_UNDECORATED);
    while (ui.isOpen()) 
    {
        ui.resizable(dragFromResize, dragToResize);
        ui.draggable(dragFrom, dragTo);
        ui.render(RAYWHITE);
    }
    ui.close();
}