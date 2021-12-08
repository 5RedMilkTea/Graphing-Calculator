#include "negative.h"

Negative::Negative():Operators(" ", 5)
{

}

Negative::Negative(string sign):Operators(sign, 5)
{

}

int Negative::getType()
{
    return 5;
}
