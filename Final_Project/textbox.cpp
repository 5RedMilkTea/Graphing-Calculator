#include <textbox.h>

//CTOR
Textbox::Textbox()
{
    isSelected = false;

    hasLimit = false;
}

Textbox::Textbox(int size, sf::Color color, bool selected)
{
    textbox.setCharacterSize(size);
    textbox.setColor(color);
    isSelected = selected;

    if (selected)
    {
        textbox.setString("_");
    }
    else
    {
        textbox.setString("");
    }

    hasLimit = false;
}

//Sets font
void Textbox::setFont(sf::Font &font)
{
    textbox.setFont(font);
}

//Sets Position
void Textbox::setPosition(sf::Vector2f pos)
{
    textbox.setPosition(pos);

}

//Set Limit
void Textbox::setLimit(bool onOff)
{
    hasLimit = onOff;
}

void Textbox::setLimit(bool onOff, int lim)
{
    hasLimit = onOff;
    limit = lim - 1;
}

//Set Selected
void Textbox::setSelected(bool sel)
{
    isSelected = sel;
    if (!sel)
    {
        std::string t = text.str();
        std::string newT = "";
        for (int i = 0; i < t.length(); i++)
        {
            newT += t[i];
        }
        textbox.setString(newT);
    }
}

//Returns text
std::string Textbox::getText()
{
    return text.str();
}

//Draws textbox
void Textbox::draw(sf::RenderWindow& window)
{
    window.draw(textbox);
}

//Does the actual text input stuff
void Textbox::type(sf::Event &input)
{
    //If textbox is selected
    if (isSelected)
    {
        //Gets unicode of the char
        int charTyped = input.text.unicode;
        //Takes in 'valid' chars only
        if (charTyped < 128)
        {
            //If char limit exists
            if (hasLimit)
            {
                if (text.str().length() <= limit)
                {
                    inputLogic(charTyped);
                }
                //Allows user to access inputLogic function if exceed limit
                else if ((text.str().length() >= limit)
                         && charTyped == DELETE_KEY)
                {
                    deleteLastChar();
                }
            }
            else
            {
                inputLogic(charTyped);
            }
        }
    }
}


//PRIVATE MEMBER FUNCTIONS
//Character Cases
void Textbox::inputLogic(int charTyped)
{
    if (charTyped != DELETE_KEY && charTyped != ENTER_KEY
            && charTyped != ESCAPE_KEY)
    {
        text << static_cast<char>(charTyped);
    }
    else if (charTyped == DELETE_KEY)
    {
        if (text.str().length() > 0)
        {
            deleteLastChar();
        }
    }
    textbox.setString(text.str() + "_");
}

void Textbox::deleteLastChar()
{
    std::string t = text.str();
    std::string newT = "";
    for (int i = 0; i < t.length() - 1; i++)
    {
        newT += t[i];
    }
    //Clears text
    text.str("");
    //Pushes newT
    text << newT;

    textbox.setString(text.str());
}
