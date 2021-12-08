#include "trigfunctions.h"

TrigFunctions::TrigFunctions():Operators (" ", 4)
{

}

TrigFunctions::TrigFunctions(string trig):Operators (trig, 4)
{

}

int TrigFunctions::getType()
{
    return 4;
}
