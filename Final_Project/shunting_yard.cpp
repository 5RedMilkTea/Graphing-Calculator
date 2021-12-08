#include "shunting_yard.h"

//DEFAULT CTOR
Shunting_Yard::Shunting_Yard()
{

}

Shunting_Yard::Shunting_Yard(queue<Token*> infix)
{
    _infix = infix;
}

//Changes infix to postfix expression
queue<Token*> Shunting_Yard::postfix()
{

    queue<Token*> returnThis;
    stack<Token*> holdOp;

    while (_infix.isEmpty() == false)
    {
        //Number/variable
        if (_infix.front()->getType() == 1 || _infix.front()->getType() == 3)
        {
            //Pushes Number/Variable into postfix
            returnThis.push(_infix.pop());
        }
        //Checks if stack is empty and if precedence of operator is lower than
            //operator in stack
        else if (!holdOp.isEmpty() && holdOp.top()->getType() != 6 &&
                 static_cast<Operators*>(_infix.front())->precedence() <=
                 static_cast<Operators*>(holdOp.top())->precedence())
        {
            returnThis.push(holdOp.pop());
        }
        //Parenthesis
        else if (_infix.front()->getType() == 7) //R Parenthesis
        {
            while (holdOp.top()->getType() != 6) //L Parenthesis
            {
                returnThis.push(holdOp.pop());
            }
            //Pop Right Parenthesis
            _infix.pop();
            //Pop Left Parenthesis
            holdOp.pop();
        }
        else
        {
            //Push Operator into stack
            holdOp.push(_infix.pop());
        }

    }
    //Returns operators left in stack until queue is empty
    while (holdOp.isEmpty() == false)
    {
        returnThis.push(holdOp.pop());
    }
    return returnThis;
}
