#ifndef RPN_H
#define RPN_H

#include "../../Stack and Queue/IteratedQueue/queue/queue.h"
#include "../../Stack and Queue/IteratedStack/stack/stack.h"
#include "token.h"
#include <numbers.h>
#include <operators.h>
#include <variables.h>


//Takes in a postfix expresssion from shunting yard
class rpn
{
public:
    rpn();
    rpn(queue<Token*> postfix);
    //Evaluate expression
    double evaluate();
    //Evaluate expression with variable
    double evaluate(double x);

private:
    //Holds evaluated value
    queue<Token*> _hold;
    //Stack of evaluated token*
    stack<double> _evaluate;
};
#endif // RPN_H
