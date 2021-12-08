#ifndef LPARENTHESIS_H
#define LPARENTHESIS_H
#include "operators.h"

//Left Parenthesis
class LParenthesis: public Operators
{
public:
    //CTor
    LParenthesis();
    LParenthesis(string sign);

    //5
    int getType();
};

#endif // LPARENTHESIS_H
