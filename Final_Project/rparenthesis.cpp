#include "rparenthesis.h"

//Default CTOR
RParenthesis::RParenthesis():Operators(" ", 7)
{

}

RParenthesis::RParenthesis(string sign):Operators(sign, 7)
{

}

int RParenthesis::getType()
{
    return 7;
}

