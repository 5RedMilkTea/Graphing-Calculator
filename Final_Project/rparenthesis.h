#ifndef RPARENTHESIS_H
#define RPARENTHESIS_H
#include "operators.h"

//Token Right Parenthesis
class RParenthesis:public Operators
{
public:
    RParenthesis();
    RParenthesis(string sign);

    //Returns 6
    int getType();
};

#endif // RPARENTHESIS_H
