#include "system.h"

//CTors
System::System()
{

}

System::System(graph_info* info):sidebar(WORK_PANEL, SIDE_BAR)
{
    _info = info;

}

//Draw everything
void System::Draw(sf::RenderWindow& window)
{
    //Create x-y axis and draw onto window
    Graph.createAxes(_info);

    //Draws Graph
    Graph.drawGraph(window, _info);

    //Draws Sidebar
    sidebar.draw(window);

    //Show on window
    window.display();

    //Display mouse position
    sidebar[0] = mouse_pos_string(window, _info);

    //Counter for Text Vector index
    int i = 2;
    string equation;
    //Display history
    _File.open("Equations.txt");
    while (getline(_File, equation))
    {
        sidebar[i] = equation;
        i++;
        if ( i == 20 )
        {
            i = 2;
        }
    }
    _File.close();
}


void System::processEvents(sf::RenderWindow &window, bool& mouseHeld,
                           double& initial_x, double& initial_y)
{
    sf::Event event;

    //go through all the pending events: keyboard, mouse, close, resize, etc.
    //pollEvent and waitEvent are the only two functions that can fill event
    while (window.pollEvent(event))//or waitEvent
    {
        // check the type of the event...
        switch (event.type)
        {
        case sf::Event::TextEntered:
            sidebar.equation.type(event);
            break;
        // window closed
        // "close requested" event: we close the window
        case sf::Event::Closed:
            window.close();
            _File.close();
            break;
        // key pressed
        case sf::Event::KeyPressed:
            //Enter equation
            if (event.key.code == sf::Keyboard::Space)
            {
                cout << "Spacebar pressed!" << endl;
                sidebar.equation.setSelected(true);
            }
            //Reset Translation
            else if (event.key.code == sf::Keyboard::R)
            {
                cout << "R key pressed! " << endl;
                //Resets to set domain
                _info->_domain = sf::Vector2f(-5,5);
                _info->y_offset = 0;
                //Updates Graph Info
                _info->update();
            }
            //Pan Right
            else if (event.key.code == sf::Keyboard::Right)
            {
                cout << "Right Key Pressed! " << endl;
                //Panning
                //Increments Domain
                _info->_domain.x++;
                _info->_domain.y++;
                //Updates Graph Info
                _info->update();
            }
            //Pan Left
            else if (event.key.code == sf::Keyboard::Left)
            {
                cout << "Left Key Pressed! " << endl;
                //Panning
                //Increments Domain
                _info->_domain.x--;
                _info->_domain.y--;
                //Updates Graph Info
                _info->update();
            }
            //Pan Up
            else if (event.key.code == sf::Keyboard::Up)
            {
                cout << "Up Key Pressed! " << endl;
                //Changes offset
                _info->y_offset--;
                //Updates Graph Info
                _info->update();
            }
            //Pan Down
            else if (event.key.code == sf::Keyboard::Down)
            {
                cout << "Down Key Pressed! " << endl;
                //Changes offset
                _info->y_offset++;
                //Updates Graph Info
                _info->update();
            }
            //Zoom in
            else if (event.key.code == sf::Keyboard::I)
            {
                cout << "I Key Pressed! " << endl;
                //Limits zoom
                if (_info->length >= 1.5)
                {
                    //Zoom in
                    _info->_domain.x /= 1.25f;
                    _info->_domain.y /= 1.25f;
                    //Updates Graph Info
                    _info->update();
                }
                else
                {
                    cout << "Max zoom-in reached!" << endl;
                }
            }
            //Zoom out
            else if (event.key.code == sf::Keyboard::O)
            {
                cout << "O Key Pressed! " << endl;
                //Limits zoom
                if (_info->length <= 125)
                {
                    //Zoom out
                    _info->_domain.x *= 1.25f;
                    _info->_domain.y *= 1.25f;
                    //Updates Graph Info
                    _info->update();
                }
                else
                {
                    cout << "Max zoom-out reached!" << endl;
                }
            }
            //Exits Textbox
            else if (event.key.code == sf::Keyboard::Escape)
            {
                cout << "esc Key Pressed! " << endl;
                //Sets textbox selection to false
                sidebar.equation.setSelected(false);

                //Updates Graph_info to input equation
                _info->_equation = sidebar.equation.getText();

                //Display to console
                cout << "Equation: " << sidebar.equation.getText() <<endl;

                //Append to external file
                _File.open("Equations.txt" , ios::app);
                _File << endl << sidebar.equation.getText();
                //Bad Design, but it won't synchronize if I don't close this
                _File.close();
            }
            //...
            break;

        //Mouse held drag
        case sf::Event::MouseButtonPressed:
            cout << "Mouse Button Pressed" << endl;
            initial_x = event.mouseButton.x;
            initial_y = event.mouseButton.y;
            mouseHeld = true;

            cout << "Inital Mouse position: (" << (event.mouseButton.x -
                                      _info->origin.x)/ _info->_scale.x << ", "
                 << (-(event.mouseButton.y - _info->origin.y)/_info->_scale.y)
                 << ") " << endl << endl;

            break;
        case sf::Event::MouseMoved:
            if (mouseHeld)
            {
                _info->_domain.x -= (((event.mouseMove.x - _info->origin.x) /
                                     _info->_scale.x) - ((initial_x -
                                       _info->origin.x) / _info->_scale.x))/50;
                _info->_domain.y -= (((event.mouseMove.x - _info->origin.x) /
                                      _info->_scale.x) - ((initial_x -
                                       _info->origin.x) / _info->_scale.x))/50;
                _info->y_offset -= (((event.mouseMove.y - _info->origin.y) /
                                     _info->_scale.y) - ((initial_y -
                                       _info->origin.y) / _info->_scale.y))/50;
            }

            break;
        //Returns grid coordinates based on mouse position
        case sf::Event::MouseButtonReleased:
            cout << "Mouse Button released" << endl;
            if (event.mouseButton.button == sf::Mouse::Right)
            {
                std::cout << "the right mouse click" << std::endl;
                cout << "(" <<
                     ((event.mouseButton.x - _info->origin.x)/_info->_scale.x)
                     << ", " <<
                     (-(event.mouseButton.y - _info->origin.y)/_info->_scale.y)
                     << ") \n";
            }
            else if (event.mouseButton.button == sf::Mouse::Left)
            {
                std::cout<<"left button"<<std::endl;
                cout << "(" <<
                 ((event.mouseButton.x - _info->origin.x)/_info->_scale.x)
                 << ", " <<
                 (-(event.mouseButton.y - _info->origin.y)/_info->_scale.y)
                 << ") \n\n";
            }
            mouseHeld = false;
            break;
        //Zooming for mouse scroll
        case sf::Event::MouseWheelMoved:
            //MOUSE SCROLL UP - ZOOM IN
            if (event.mouseWheel.delta == 1)
            {
                cout << "Scrolled up" << endl;
                if (_info->length >= 1.5)
                {
                    _info->_domain.x /= 1.1f;
                    _info->_domain.y /= 1.1f;
                    _info->update();
                }
                else
                {
                    cout << "Max zoom-in reached!" << endl;
                }
            }
            //MOUSE SCROLL DOWN - ZOOM OUT
            else if (event.mouseWheel.delta == -1)
            {
                cout << "Scrolled down" << endl;
                if (_info->length <= 125)
                {
                    _info->_domain.x *= 1.15f;
                    _info->_domain.y *= 1.15f;
                    _info->update();
                }
                else
                {
                    cout << "Max zoom-out reached!" << endl;
                }
            }
        break;

        default:
            break;
        }
        //DEBUG
        /*
        cout << endl << "*****Graph Info*****" << endl;
        cout << "Scale: " << _info->_scale.x << endl;
        cout << "Length: " << _info->length << endl;
        cout << "Offset: " << (_info->length/2) * (_info->_scale.x) << endl;
        cout << "Points: " << _info->_points << endl << endl;
        */
    }
}

//Returns string grid position based on mouse position
string mouse_pos_string(sf::RenderWindow& window, graph_info* info){
    return "(" +
            to_string(((sf::Mouse::getPosition(window).x - info->origin.x)
                       / info->_scale.x)) + ", " +
            to_string(-(sf::Mouse::getPosition(window).y - info->origin.y) /
                      info->_scale.y) + ")";
}
