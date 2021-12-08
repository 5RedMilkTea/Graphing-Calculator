#include "test_functions.h"

void test_rpn()
{
    queue<Token*> postfix;

    // 5 + 2
    /*
    postfix.push(new numbers("5"));

    postfix.push(new variables("x"));

    postfix.push(new Operators("^"));


    postfix.push(new numbers("5"));

    postfix.push(new numbers("15"));

    postfix.push(new Operators("*"));



    postfix.push(new Operators("+"));

    */
    cout << postfix << endl;

    rpn test(postfix);

    cout << "RPN RESULT: " << test.evaluate() << endl;

}

void test_shunting_yard()
{
    queue<Token*> infix;

    /*
    infix.push(new numbers("3"));

    infix.push(new Operators("*"));
    infix.push(new LParenthesis("("));

    infix.push(new numbers("5"));

    infix.push(new Operators("-"));
    infix.push(new LParenthesis("("));

    infix.push(new numbers("6"));

    infix.push(new Operators("+"));

    infix.push(new numbers("7"));

    infix.push(new RParenthesis(")"));
    infix.push(new Operators("/"));
    infix.push(new LParenthesis("("));

    infix.push(new numbers("2"));
    infix.push(new Operators("*"));
    infix.push(new numbers("8"));
    infix.push(new Operators("+"));
    infix.push(new numbers("4"));
    infix.push(new RParenthesis(")"));
    infix.push(new RParenthesis(")"));
    infix.push(new Operators("*"));
    infix.push(new numbers("9"));
    */

    infix.push(new variables("x"));

    infix.push(new Operators("*"));

    infix.push(new TrigFunctions("sin"));

    infix.push(new LParenthesis("("));

    infix.push(new numbers("1"));

    infix.push(new Operators("/"));

    infix.push(new variables("x"));

    infix.push(new RParenthesis(")"));


    cout << "Infix: " << infix << endl;

    Shunting_Yard a(infix);
    queue<Token*> postfix;
    postfix = a.postfix();
    cout << "Postfix: " << postfix << endl;
    rpn test(postfix);

    cout << "RPN RESULT: " << test.evaluate(2) << endl;


    //rpn test(a.postfix());
    //cout << endl;
    //cout << "RPN: " << test.evaluate() << endl;

}

void test_tokenizer()
{
    string hold;
    cout << ": ";
    getline(cin, hold);

    cout << "Token Hold " << endl;
    tokenizer token(hold);
    cout << "---Shunting Yard---" << endl;
    cout << "Test token.convert: " << token.convert() << endl;
    Shunting_Yard yard(token.convert());
    cout << "postfix copy" << endl;
    queue<Token*> postfix = yard.postfix();
    cout << "Postfix: " << postfix << endl;
    cout << "---RPN---" << endl;
    rpn result(postfix);
    for (double i = 0; i < 5; i++)
    {
        cout << "i: " << i << endl;
        cout << "Result: " << result.evaluate(i) << endl;
    }

}
