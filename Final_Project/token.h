#ifndef TOKEN_H
#define TOKEN_H
#include<iostream>
using namespace std;

class Token
{
public:
    //CTOR
    Token();
    Token(int type);
    Token(string Tstring, int type);

    //Destructor
    virtual ~Token();
    virtual void print() const;
    //1 for numbers
    //2 for operators
    //3 for variables
    //4 Trig
    //5 ~ unary "-"
    //6 for left parenthesis
    //7 for right parenthesis
    virtual int getType();

    //Output
    friend ostream& operator << (ostream& outs, Token* rhs)
    {
        rhs->print();

        return outs;
    }

private:
    //Token Type
    int _type;

    //Token string
    string T_string;
};

#endif // TOKEN_H
