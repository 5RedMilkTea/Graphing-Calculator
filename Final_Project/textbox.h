#ifndef TEXTBOX_H
#define TEXTBOX_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox
{
public:
    //Constructors
    Textbox();
    Textbox(int size, sf::Color color, bool selected);

    //Mutators
    void setFont(sf::Font& font);
    void setPosition(sf::Vector2f pos);
    void setLimit(bool onOff);
    void setLimit(bool onOff, int lim);
    void setSelected(bool sel);

    std::string getText();
    void draw(sf::RenderWindow& window);
    void type(sf::Event& input);

private:
    //Text itself
    sf::Text textbox;
    std::ostringstream text;
    //If the textbox is selected
    bool isSelected = false;
    //Number of characters reached
        //Want to change it so the fontsize decreases when window reached.
    bool hasLimit = false;
    //Limit on number of characters input
    int limit;

    //Performs computation
    void inputLogic(int charTyped);
    //Deleting characters (backspace)
    void deleteLastChar();

};



#endif // TEXTBOX_H
