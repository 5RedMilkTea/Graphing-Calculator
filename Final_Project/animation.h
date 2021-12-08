#ifndef ANIMATION_H
#define ANIMATION_H

#include <system.h>

class Animation
{
public:
    //Constructors
    Animation();
    Animation(graph_info* info);
    //Executes Program
    void run();
    //Process Events in window
    void processEvents();
    //Returns true if window is open
    bool open();


private:
    //Private members
    sf::RenderWindow window;
    //Graph data
    graph_info* _info;
    //System object
    System system;
};




#endif // ANIMATION_H
