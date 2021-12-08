#ifndef NEGATIVE_H
#define NEGATIVE_H
#include "operators.h"

class Negative:public Operators
{
public:
    Negative();
    Negative(string sign);

    //6
    int getType();
};

#endif // NEGATIVE_H
