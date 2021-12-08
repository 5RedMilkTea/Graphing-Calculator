#include "operators.h"

//Default CTor
Operators::Operators():Token(2)
{

}


Operators::Operators(string sign):Token(sign, 2)
{
    _sign = sign;
    //Sets precedence based on sign
    if (sign == "+" || sign == "-")
    {
        order = 0;
    }
    else if (sign == "*" || sign == "/")
    {
        order = 1;

    }
    else if (sign == "^")
    {
        order = 2;
    }
}

Operators::Operators(string sign, int type):Token(sign, type)
{
    _sign = sign;
    //Sets precedence for higher precedence functions
    if (sign == "(")
    {
        order = 6;
    }
    else if (sign == ")")
    {
        order = 7;
    }
    else if (sign == "sin" || sign == "cos" || sign == "tan" || sign == "cot"
             || sign == "csc" || sign == "sec" || sign == "sinh"
             || sign == "cosh" || sign == "tanh" || sign == "log"
             || sign == "arcsin" || sign == "arccos" || sign == "arctan" ||
             sign == "~")
    {
        order = 4;
    }
    else if (sign == "~")
    {
        order = 10;
    }
}

//Returns Token Type
int Operators::getType()
{
    return 2;
}

//Outputs the operator
void Operators::print() const
{
    cout << _sign;
}

//Returns operator
string Operators::sign()
{
    return _sign;
}

//Returns precedence
int Operators::precedence()
{
    return order;
}

//Evaluates Trig expressions and returns result
double Operators::evaluate(const double& expression)
{
    double result = 0;
    //Trig Functions
    //Sin
    if (_sign == "sin")
    {
        result = sin(expression);
    }
    //Cos
    else if (_sign == "cos")
    {
        result = cos(expression);
    }
    //Tan
    else if (_sign == "tan")
    {
        result = tan(expression);
    }
    //Cosecant
    else if (_sign == "csc")
    {
        result = 1/sin(expression);
    }
    //Secant
    else if (_sign == "sec")
    {
        result =  1/cos(expression);
    }
    //Cotangent
    else if (_sign == "cot")
    {
        result = 1/tan(expression);
    }
    //Inverse Trig
    //Arcsin
    else if (_sign == "arcsin")
    {
        result = asin(expression);
    }
    //Arccos
    else if (_sign == "arccos")
    {
        result = acos(expression);
    }
    //Arctan
    else if (_sign == "arctan")
    {
        result = atan(expression);
    }
    //Hyperbolics
    //sinh
    else if (_sign == "sinh")
    {
        result = sinh(expression);
    }
    else if (_sign == "cosh")
    {
        result = cosh(expression);
    }
    else if (_sign == "tanh")
    {
        result = tanh(expression);
    }
    //I grouped Log as the same precedence as trig functions
    else if (_sign == "log")
    {
        result = log(expression);
    }
    else if (_sign == "~")
    {
        result = expression * -1;
    }
    return result;
}

//Evaluates Arithmetic expressions and returns result
double Operators::evaluate(const double& lhs, const double& rhs)
{

    double result = 0;

    if (_sign == "+")
    {
        result = lhs + rhs;
    }
    else if (_sign == "-")
    {
        result = rhs - lhs;
    }
    else if (_sign == "*")
    {
        result = lhs * rhs;
    }
    else if (_sign == "/")
    {
        result = rhs / lhs;
    }
    else if (_sign == "^")
    {
        result =  pow(rhs, lhs);
    }
    return result;
}

