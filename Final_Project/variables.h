#ifndef VARIABLES_H
#define VARIABLES_H

#include <token.h>

class variables : public Token
{
public:
    //CTors
    variables();
    variables(string var);

    //Returns Type
    int getType();
    void print() const;

    //Output
    friend ostream& operator << (ostream& outs, const variables& rhs)
    {
        outs << "Variable: " << rhs._var << endl;
        return outs;
    }

private:
    string _var;
};

#endif // VARIABLES_H
