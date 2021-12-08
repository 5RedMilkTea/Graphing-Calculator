#include "numbers.h"

//CTors
numbers::numbers():Token(1)
{
    _num = NULL;
}

numbers::numbers(double num):Token(1)
{
    _num = num;
}

numbers::numbers(string num):Token(num, 1)
{
    _num = stod(num);
}

//Big 3 copy
numbers::numbers(const numbers& copy)
{
    _num = copy._num;
}

//Big 3 = operator
numbers& numbers::operator = (const numbers &rhs)
{
    _num = rhs._num;
    return *this;
}

//Big 3 Destructor
numbers::~numbers()
{

}

//Returns double
double numbers::number()
{
    return _num;
}

int numbers::getType()
{
    return 1;
}

void numbers::print() const
{
    cout << _num;
}
