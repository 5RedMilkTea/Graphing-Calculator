#include "rpn.h"

//Default CTOR
rpn::rpn()
{
    //Intentionally empty
}
//
rpn::rpn(queue<Token*> postfix)
{
    _hold = postfix;
}

//Solves the equation
double rpn::evaluate()
{
    //If expression is empty and theres nothing to evaluate
    if (_hold.isEmpty())
    {
        return NULL;
    }
    //Checks if the token popped from queue is an operator
    queue<Token*> hold = _hold;
    while (hold.isEmpty() == false)
    {
        //NUMBERS
        if (hold.front()->getType() == 1)
        {
            //Push into stack
            _evaluate.push(static_cast<numbers*>(_hold.pop())->number());
        }
        //TRIG
        else if (hold.front()->getType() == 4 || hold.front()->getType() == 5)
        {
            Token* trig = _hold.pop();
            assert(trig->getType() == 4);
            double expression = _evaluate.pop();
            _evaluate.push(static_cast<Operators*>(trig)->
                           evaluate(expression));
        }
        //ARITHMETIC OPERATORS
        else
        {
            //Pop operator from queue
            Token* operate = _hold.pop();

            assert(operate->getType() == 2);

            //Pop twice from stack
            double t1 = _evaluate.pop();
            double t2 = _evaluate.pop();

            //Pushes evaluation to stack
            _evaluate.push(static_cast<Operators*>(operate)->evaluate(t1, t2));

        }
    }
   //Returns top value of stack as a double
   return _evaluate.top();
}




//Returns a value from function when given value for x
double rpn::evaluate(double x)
{
    //If expression is empty
    if (_hold.isEmpty())
    {
        return NULL;
    }

    //Soft Copy
    queue<Token*> hold = _hold;
    while (hold.isEmpty() == false)
    {
        //If its a variable
        if (hold.front()->getType() == 3)
        {
            //Pops the variable
            hold.pop();
            //Push variable number here********************
            _evaluate.push(x);
        }
        else if (hold.front()->getType() == 1)
        {
            //Push into stack
            _evaluate.push(static_cast<numbers*>(hold.pop())->number());
        }
        else if (hold.front()->getType() == 4 || hold.front()->getType() == 5)
        {
            Token* trig = hold.pop();
            assert(trig->getType() == 4 || trig->getType() == 5);
            double expression = _evaluate.pop();
            _evaluate.push(static_cast<Operators*>(trig)->evaluate(expression));
        }
        else
        {
            //Pop operator from queue
            Token* operate = hold.pop();
            assert(operate->getType() == 2);

            //Pop twice from stack
            double t1 = _evaluate.pop();
            double t2 = _evaluate.pop();

            //Pushes evaluation to stack
            _evaluate.push(static_cast<Operators*>(operate)->evaluate(t1, t2));
        }
    }
   //Returns top value of stack as a double
   return _evaluate.top();
}
