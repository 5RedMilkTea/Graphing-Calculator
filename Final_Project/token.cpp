#include "token.h"
//Constructors
Token::Token()
{
    _type = 0;
    T_string = "Default Token";
}

Token::Token(int type)
{
    _type = type;
    if (type == 1)
    {
        T_string = "Number Token";
    }
    else if (type == 2)
    {
        T_string = "Operator Token";
    }
    else if (type == 3)
    {
        T_string = "Variable Token";
    }
    else if (type == 4)
    {
        T_string = "Trig Token";
    }
    else
    {
        T_string = "Default";
    }

}

Token::Token(string Tstring, int type)
{
    _type = type;
    T_string = Tstring;
}

Token::~Token()
{
    //Empty
    //Debugger
    cout << "----------Token Destructor called----------" << endl;
}

//Outputs string
void Token::print() const
{
    cout << T_string;
}

//Returns Type
int Token::getType()
{
    cout << "Token Type returned" << endl;
    return 0;
}
