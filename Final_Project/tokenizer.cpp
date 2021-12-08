#include "tokenizer.h"

//CTors
tokenizer::tokenizer()
{

}

tokenizer::tokenizer(string expression)
{
    _expression = expression;
}

//Changes string to queue of tokens
queue<Token*> tokenizer::convert()
{
    queue<Token*> infix;

    char cstring[1000];
    //c_str converts string to c_string
    //Copying string to cstring
    strcpy(cstring, _expression.c_str());

    char* tok = strtok(cstring, " ");
    while (tok != nullptr)
    {
        if (isdigit(*tok))
        {
            infix.push(new numbers(tok));
        }
        else if (tolower(*tok) == 'x')
        {
            infix.push(new variables(tok));
        }
        else if (*tok == '*' || *tok == '/' || *tok == '^' || *tok == '+'
                 || *tok == '-')
        {
            infix.push(new Operators(tok));
        }
        else if (*tok == '(')
        {
            infix.push(new LParenthesis(tok));
        }
        else if (*tok == ')')
        {
            infix.push(new RParenthesis(tok));
        }
        else if (*tok == '~')
        {
            infix.push(new Negative(tok));
        }
        //This is a litte bit wonky and prone to user error
        else
        {
            infix.push(new TrigFunctions(tok));
        }
        tok = strtok(nullptr, " ");
    }
    return infix;    
}

void tokenizer::fix_string()
{

}
