#include "variables.h"

variables::variables()
{
    _var = "x";
}

variables::variables(string var)
{
    _var = var;
}

int variables::getType()
{
    return 3;
}

void variables::print() const
{
    cout << _var;
}

