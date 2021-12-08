#include "sidebar.h"

#include "sidebar.h"
#include "graph.h"
#include <cstring>
Sidebar::Sidebar(){

}

Sidebar::Sidebar(float left, float width)
    :_left(left), _width(width), equation(25, sf::Color::Black, false)
{
    cout<<"Sidebar CTOR: TOP"<<endl;
    items.reserve(100);

    //set up the sidebar rectangle:
    rect.setFillColor(sf::Color(255, 245, 210)); //(192,192,192)); //silver
    rect.setPosition(sf::Vector2f(left, 0));
    rect.setSize(sf::Vector2f(width, SCREEN_HEIGHT));

    //Legend Area
    cout << "Legend Loaded: " << endl;
    //Sets size
    key.setSize(sf::Vector2f(width, SCREEN_HEIGHT / 3));
    //Sets color of background for legend
    key.setFillColor(sf::Color(255, 220, 150));
    //Sets position
    key.setPosition(sf:: Vector2f(left, SCREEN_HEIGHT * 4/5));

    //Textbox Object
    cout << "Textbox Loaded: " << endl;
    //Sets size
    Tbg.setSize(sf::Vector2f(width, 35));
    //Sets color of background for legend
    Tbg.setFillColor(sf::Color(150, 220, 255));
    //Sets position
    Tbg.setPosition(sf::Vector2f(left, (SCREEN_HEIGHT * 3/5) - 2));
    equation.setPosition(sf::Vector2f(left, SCREEN_HEIGHT * 3/5));

    cout<<"Sidebar CTOR: about to load font."<<endl;

    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
    //the font file must be in the "working directory"
    // check projects->run->working directory
    //      [Make sure it's not pointing to the app file]

    if (!font.loadFromFile("arial.ttf")){
        cout<<"Sidebar() CTOR: Font failed to load"<<endl;
        cin.get();
        exit(-1);
    }
    ////- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -

    cout<<"Sidebar CTOR: loaded font."<<endl;

    //. . . . . text / font problems: . . . . . . . .
    //initializing text object in this way caused problems
    // (hangs!)
    //only when sb_text was a private member and worked fine
    //when it was a public member. Probably not releavant,
    //but still strange!
    //
    //sb_text = sf::Text("Initial String for myTextLabel", font);
    //
    //. . . . . . . . . . . . . . . . . . . . . . . . .
    cout<<"Sidebar CTOR: Text object initialized."<<endl;

    sb_text.setCharacterSize(30);
    sb_text.setStyle(sf::Text::Bold);
    sb_text.setColor(sf::Color::Black);

    Legend.setCharacterSize(35);
    Legend.setStyle(sf::Text::Italic | sf::Text::Bold);
    Legend.setColor(sf::Color::Red);

    Enter.setCharacterSize(30);
    Enter.setStyle(sf::Text::Bold);
    Enter.setColor(sf::Color(0, 50, 255));

    ////this is how you would position text on screen:
    //sb_text.setPosition(sf::Vector2f(10, SCREEN_HEIGHT-sb_text.getLocalBounds().height-5));

    items.push_back("sidebar sample text");
    //Fill the items vector with empty strings so that we can use [] to read them:
    for (int i=0 ; i < 15; i++)
    {
        if (i == 0)
        {
            items.push_back("History: ");
        }
        items.push_back("");
    }
    cout<<"Sidebar: CTOR: Exit."<<endl;
}

void Sidebar::draw(sf::RenderWindow& window)
{
    //Spacing for sidebar text
    const double VERTICAL_LINE_SPACING = 7.5;
    const double LEFT_MARGIN = 10.0;

    //Setting font for text
    sb_text.setFont(font);
    Legend.setFont(font);
    Enter.setFont(font);
    equation.setFont(font);

    //Draw backgrounds for sidebar
    //Sidebar background
    window.draw(rect);
    //Legend background
    window.draw(key);
    //Textbox background
    window.draw(Tbg);

    float height = 10;

    //LEGEND
    //Set string
    Legend.setString("KEYS:\n [ARROW Keys] move \n [I] Zoom In \n "
                     "[O] Zoom Out \n [R] Reset \n [SPACEBAR] Entry \n "
                     "[esc] Exit Entry \n");
    //Sets position of Legend box
    Legend.setPosition(sf::Vector2f(_left, SCREEN_HEIGHT * 4/5));
    window.draw(Legend);

    //ENTER
    Enter.setString("Enter Equation");
    Enter.setPosition(sf::Vector2f(_left, (SCREEN_HEIGHT * 3/5) - 50));
    window.draw(Enter);

    //Sets position of textbox and draws it
    equation.setPosition(sf::Vector2f(_left, SCREEN_HEIGHT * 3/5));
    equation.draw(window);

    for (vector<string>::iterator it = items.begin();
                                it!= items.end(); it++)
    {
        bool blank = false;
        if (strlen(it->c_str()) == 0){
            //empty rows must be taken into account (getLocalBounds())
            //    but not drawn
            blank = true;
            sb_text.setString("BLANK");
        }
        else{
            sb_text.setString(it->c_str());
        }

        sb_text.setPosition(sf::Vector2f(_left+LEFT_MARGIN, height));
        height += sb_text.getLocalBounds().height+VERTICAL_LINE_SPACING * 3;
        if (!blank)
            window.draw(sb_text);
    }
}

string& Sidebar::operator [](int index){
    return items[index];
}
