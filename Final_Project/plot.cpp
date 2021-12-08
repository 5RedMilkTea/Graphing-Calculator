#include "plot.h"

//CTors
plot::plot()
{
    _info = nullptr;
}

plot::plot(graph_info* info)
{
    _info = info;
}

//Translate grid coordinates to screen coordinates
sf::Vector2f plot::translate(double x, double y)
{
    sf::Vector2f coordinate;

    coordinate.x = ((x * _info->_scale.x) + _info->origin.x);
    coordinate.y = (-(y * _info->_scale.y) + _info->origin.y);

    //DEBUG
    /*
    cout << "Coordinate: " << "( " << x << " , " << y << " )" << endl;
    cout << "Grid Translated 'x': " << coordinate.x << endl;
    cout << "Grid Translated 'y': " << coordinate.y << endl;
    */

    return coordinate;
}

//Calculates where each point should be
vector<sf::Vector2f> plot::coordinates(graph_info* graph)
{
    //Vector to hold coordinates
    vector<sf::Vector2f> coordinates;

    //Changes string equation into tokens
    tokenizer infix(graph->_equation);
    //Converts tokens from infix notation to postfix
    Shunting_Yard postfix(infix.convert());
    //sets a separate queue to copy the tokens
    queue<Token*> fixed = postfix.postfix();

    //Declaration of RPN object
    rpn value(fixed);

    //RPN evaluates objects and pushes back coordinates to vector
    for (double i = _info->_domain.x; i < _info->_domain.y;
         i += _info->_scale.x/(_info->_window_Dimension.x * 5))
    {
        coordinates.push_back(sf::Vector2f(this->translate(i, value.evaluate(i))));
    }

    _info->_points = coordinates.size();
    //DEBUG - output of what is inside vector
    /*
    cout << endl;
    cout << endl;
    for (int i = 0; i < coordinates.size(); i++)
    {
        cout << "(" << coordinates.at(i).x << ", " << coordinates.at(i).y
             << ")";
    }
    */

    return coordinates;
}

bool plot::empty()
{
    return (_info->_equation == "" || _info->_equation == " "
            || _info->_equation == "  ");
}
