#include "animation.h"

//Default CTOR
Animation::Animation()
{
    //Creates Window
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Dismos");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    system = System();
}

//CTor
Animation::Animation(graph_info* info)
{
    //Creates Window
    window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Dismos");
    //Sets FPS
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    //Stores graph info
    _info = info;
    //Assigns graph info to system
    system = System(info);
}

bool Animation::open()
{
    //Returns true if window is open
    return (window.isOpen());
}

//Run the program
void Animation::run()
{
    //Mouse inital positions
    double initial_x;
    double initial_y;
    //Check for dragging
    bool mouseHeld = false;
    //Loop through program
    while (this->open())
    {
        //Process Events
        system.processEvents(window, mouseHeld, initial_x, initial_y);
        //Draw the stuff on the window
        system.Draw(window);
    }
}


