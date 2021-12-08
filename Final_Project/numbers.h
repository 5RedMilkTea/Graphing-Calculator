#ifndef NUMBERS_H
#define NUMBERS_H
#include "token.h"

#include <iostream>
using namespace std;

//Number Token
class numbers : public Token
{
public:
    //Constructors
    numbers();
    numbers(double num);
    numbers(string num); //Converts string to double

    //Copy CTor
    numbers(const numbers& copy);
    //Subtraction Operator
    numbers& operator = (const numbers& rhs);
    ~numbers();

    //Returns type double of the number
    double number();
    //Returns Type
    int getType();
    //Print function
    void print() const;

    //Print function
    friend ostream& operator << (ostream& outs, const numbers& rhs)
    {
        outs << "Number: " << rhs._num << endl;
        return outs;
    }

private:
    double _num;
};

#endif // NUMBERS_H
