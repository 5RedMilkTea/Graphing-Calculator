#include <iostream>
#include <fstream>
#include <test_functions.h>
#include <animation.h>

#include "lparenthesis.h"
#include "rparenthesis.h"
#include "trigfunctions.h"

#include "graph_info.h"
#include <plot.h>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

using namespace std;


int main()
{
    cout << "FINAL PROJECT" << endl;
    //*****GRAPH_INFO*****
    graph_info a;
    a._domain.x = -20;
    a._domain.y = 20;
    a.length = a._domain.y - a._domain.x;
    a._window_Dimension.x = WORK_PANEL;
    a._window_Dimension.y = SCREEN_HEIGHT;
    a._points = 10 * a.length;
    a._scale.x = a._window_Dimension.x/a.length;
    a._scale.y = a._window_Dimension.y/a.length;

    a._equation = "";

    //Graph origin
    a.origin.x = a._window_Dimension.x/2 - ((a._domain.x + a._domain.y)/2 *
                                            (a._scale.x));


    a.origin.y = a._window_Dimension.y/2;
    //setting pointer to graph info object
    graph_info* b = &a;

    //Declaration of plot object
    plot c(b);
    c.coordinates(b);

    //ANIMATION
    Animation w(b);
    //Execute program
    w.run();






    //*****TEST FUNCTIONS*****
    //test_tokenizer();
    //test_shunting_yard();
    //test_rpn();

    return 0;
}


