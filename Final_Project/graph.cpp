#include "graph.h"

graph::graph()
{

}

//Creates x-y axes
void graph::createAxes(graph_info* info)
{
    x_axis.setSize(sf::Vector2f(WORK_PANEL, AXIS_THICKNESS));
    y_axis.setSize(sf::Vector2f(AXIS_THICKNESS, SCREEN_HEIGHT));
    x_axis.setFillColor(sf::Color::Cyan);
    y_axis.setFillColor(sf::Color::Cyan);
    x_axis.setOutlineThickness(-2);
    x_axis.setOutlineColor(sf::Color::White);
    y_axis.setOutlineThickness(-2);
    y_axis.setOutlineColor(sf::Color::White);

    x_axis.setPosition(0, info->origin.y);
    y_axis.setPosition(info->origin.x, 0);
}

void graph::createGraph(sf::RenderWindow& window, graph_info* info)
{
    //Changes radius of points based on the length of the domain
    //So instead of plotting more points when the domain increases to make the
    //line look continuous, the thickness will be increased instead.
    int thicknessDivisor = 0;
    if (info->length <= 25)
    {
        thicknessDivisor = 30;
    }
    else if (info->length <= 50)
    {
        thicknessDivisor = 20;
    }
    else
    {
        thicknessDivisor = 10;
    }

    //Plots points
    plot a(info);

    if (!a.empty())
    {
        //Configures points
        vector<sf::Vector2f> coordinateList = a.coordinates(info);
        //points.setRadius(info->_scale.x/thicknessDivisor);
        points.setRadius(5);
        points.setFillColor(sf::Color::Green);
        //Graph y = x
        //Draws points onto window

        for (int i = 0; i < coordinateList.size(); i++)
        {
            //cout << "Plotting Points" << endl;
            //loop through vector and draw coordinates
            points.setPosition(coordinateList.at(i));
            window.draw(points);
            //cout << "Plot success! " << endl;
        }
    }
}

void graph::drawGraph(sf::RenderWindow& window, graph_info* info)
{
    //Clears window
    window.clear();
    //Draws x-axis
    window.draw(x_axis);
    //Draws y-axis
    window.draw(y_axis);
    //Draws function
    this->createGraph(window, info);
    //Updates Graph Info based on new domain
    info->update();

}
