#ifndef SIDEBAR_H
#define SIDEBAR_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <graph.h>
#include <textbox.h>
using namespace std;


class Sidebar
{
public:
    //Constructors
    Sidebar();
    Sidebar(float left, float width);
    //Draws everything in sidebar
    void draw(sf::RenderWindow& window);
    //Returns index in vector of string items
    string& operator [](int index);
    //Equation user inputs
    Textbox equation;
private:
    //Sidebar background
    sf::RectangleShape rect;        //sidebar rectangle
    vector<string> items;           //strings to place on the sidebar
    sf::Font font;                  //used to draw text
    sf::Text sb_text;               //used to draw strings on the window object

    //Background for legend
    sf::RectangleShape key;
    //Legend Text
    sf::Text Legend;

    //Textbox for user input equation
    //Prompts user for input
    sf::Text Enter;

    //Background
    sf::RectangleShape Tbg;

    //Position and width
    float _left;
    float _width;


};
#endif // SIDEBAR_H
