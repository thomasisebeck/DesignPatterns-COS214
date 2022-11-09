#include <iostream>
using namespace std;

class Expression {
public:
    virtual int intepretor(int value1, int value2 = 0) = 0;
};

class TerminalExpression: public Expression {
private:
    int data;
public:
    TerminalExpression(int data = 0) {
        this->data = data;
    }
    virtual int intepretor(int value1, int value2 = 0) {
        return value1;
    }
};

class Addition : public Expression {
private:
    Expression* val1;
    Expression* val2;
public:
    Addition(Expression* val1, Expression* val2) {
        this->val1 = val1;
        this->val2 = val2;
    }
    virtual int intepretor(int v1, int v2) {
        return val1->intepretor(v1) + val2->intepretor(v2);
    }
};

class Subtraction : public Expression {
private:
    Expression* val1;
    Expression* val2;
public:
    Subtraction(Expression* val1, Expression* val2) {
        this->val1 = val1;
        this->val2 = val2;
    }
    virtual int intepretor(int v1, int v2) {
        return val1->intepretor(v1) - val2->intepretor(v2);
    }
};

int main() {

    Expression* e1 = new TerminalExpression;
    Expression* e2 = new TerminalExpression;

    Expression* subtract = new Subtraction(e1, e2);
    cout << subtract->intepretor(1, 3) << endl;

    Expression* addition = new Addition(e1, e2);
    cout << addition->intepretor(2, 3);

    Expression* joined = new Addition(subtract, addition);


    return 0;
}