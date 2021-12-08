#ifndef SYSTEM_H
#define SYSTEM_H
#include <graph.h>
#include <sidebar.h>
#include <fstream>
using namespace std;

class System
{
public:
    System();
    System(graph_info* info);

    //Draws everything within the program
    void Draw(sf::RenderWindow& window);
    //Processes events
    void processEvents(sf::RenderWindow& window, bool &mouseHeld,
                       double &initial_x, double &initial_y);
private:
    //Graph object
    graph Graph;
    //Graph Info
    graph_info* _info;
    //Sidebar
    Sidebar sidebar;
    //External File
    fstream _File;

};

//Returns graph coordinates of where the mouse cursor is at
string mouse_pos_string(sf::RenderWindow& window, graph_info* info);

#endif // SYSTEM_H
