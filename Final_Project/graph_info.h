#ifndef GRAPH_INFO_H
#define GRAPH_INFO_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
using namespace std;

struct graph_info
{
    //Equation to be graphed
    string _equation;
    //Number of points
    int _points;
    //Origin of graph
    sf::Vector2f origin;
    //Window Dimension
    sf::Vector2f _window_Dimension;
    //Distance between points AKA delta x
    sf::Vector2f _scale;
    //Domain displayed in graph
    sf::Vector2f _domain;
    //Length of the domain
    double length;
    //Offset for panning in the vertical direction
    double y_offset;

    //Updates graph info members based on new domain
    void update()
    {
        length = _domain.y - _domain.x;
        //_points = 500 * length;
        _scale.x = _window_Dimension.x/length;
        _scale.y = _window_Dimension.y/length;
        origin.x = _window_Dimension.x/2 - ((_domain.x + _domain.y)/2 *
                                            (_scale.x));
        origin.y = _window_Dimension.y/2 - (y_offset * _scale.y);
    }
};


#endif // GRAPH_INFO_H
