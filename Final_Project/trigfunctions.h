#ifndef TRIGFUNCTIONS_H
#define TRIGFUNCTIONS_H
#include "operators.h"

class TrigFunctions : public Operators
{
public:
    //CTors
    TrigFunctions();
    TrigFunctions(string trig);

    //Return Type
    int getType();
};

#endif // TRIGFUNCTIONS_H
