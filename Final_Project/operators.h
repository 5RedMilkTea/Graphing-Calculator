#ifndef OPERATORS_H
#define OPERATORS_H
#include "token.h"
#include "cmath"

//Token Operators
class Operators: public Token
{
public:
    //CTors
    Operators();
    Operators(string sign);
    Operators(string sign, int type);

    //Returns Type
    int getType();
    //Prints Operator
    void print() const;
    //Returns precedence of operators
    virtual int precedence();
    //Accessor
    string sign();
    //Evaluates Trig Functions
    double evaluate(const double& expression);
    //Evaluates functions with 2 parameters
    double evaluate(const double& lhs, const double& rhs);

private:
    //The precedence of the operator
    int order;
    //The operator symbol itself
    string _sign;
};

#endif // OPERATORS_H
