#ifndef GRAPH_H
#define GRAPH_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <graph_info.h>
#include <plot.h>
#include <iostream>
#include <constants.h>


class graph
{
public:
    //Constructor
    graph();
    //Creates x-y axes
    void createAxes(graph_info* info);

    //Calls plot and creates points
    void createGraph(sf::RenderWindow& window, graph_info* info);

    //Draws everything
    void drawGraph(sf::RenderWindow& window, graph_info* info);

private:
    //X-Axis
    sf::RectangleShape x_axis;
    //Y-Axis
    sf::RectangleShape y_axis;
    //Points plotted
    sf::CircleShape points;
    // slopes
    sf::RectangleShape slopes;
};

#endif // GRAPH_H
