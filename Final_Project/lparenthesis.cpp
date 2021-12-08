#include "lparenthesis.h"

//blank and -1 b/c this constructor shouldn't be called
LParenthesis::LParenthesis():Operators(" ", 6)
{

}

LParenthesis::LParenthesis(string sign):Operators(sign, 6)
{

}

int LParenthesis::getType()
{
    return 6;
}

