#ifndef PLOT_H
#define PLOT_H
#include "graph_info.h"
#include <vector>

#include <tokenizer.h>
#include <shunting_yard.h>
#include <rpn.h>

class plot
{
public:
    //CTors
    plot();
    plot(graph_info* info);
    //Changes graph coordinates to screen coordinates
    sf::Vector2f translate(double x, double y);
    //Returns vector of screen coordinates after crunching function
    vector<sf::Vector2f> coordinates(graph_info* graph);
    //Checks if equation is empty
    bool empty();

private:
    //Stores graph info
    graph_info* _info;
};

#endif // PLOT_H
