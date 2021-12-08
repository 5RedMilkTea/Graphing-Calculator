#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H
#include "token.h"
#include "operators.h"
#include "../../Stack and Queue/IteratedQueue/queue/queue.h"
#include "../../Stack and Queue/IteratedStack/stack/stack.h"

class Shunting_Yard
{
public:
    Shunting_Yard();
    Shunting_Yard(queue<Token*> infix);

    //Returns Postfix expresssion from infix
    queue<Token*> postfix();

private:
    //Stores infix expression
    queue<Token*> _infix;
};

#endif // SHUNTING_YARD_H
