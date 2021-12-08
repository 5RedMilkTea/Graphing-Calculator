#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <token.h>
#include <numbers.h>
#include <operators.h>
#include <lparenthesis.h>
#include <rparenthesis.h>
#include <trigfunctions.h>
#include <variables.h>
#include <negative.h>

#include <cstring>
#include <cctype>
#include "../../Stack and Queue/IteratedQueue/queue/queue.h"

class tokenizer
{
public:
    //CTors
    tokenizer();
    tokenizer(string expression);
    //Changes string to tokens
    queue<Token*> convert();

    //**Work in progress**
    //Will allow user to input equation without spacebars in b/w each value
    void fix_string();

private:
    string _expression;
};

#endif // TOKENIZER_H
