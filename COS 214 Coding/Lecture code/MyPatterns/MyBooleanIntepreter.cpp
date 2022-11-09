#include <iostream>
using namespace std;

class Expression {
public:
    virtual bool

    intepretor(std::string con) = 0;
    virtual ~Expression(){}
};

class TerminalExpression: public Expression {
private:
    string data;
public:
    TerminalExpression(string data) {
        this->data = data;
    }

    //The interpreter either finds the string or not
    bool intepretor(string con) {
        cout << "Evaluating TERMINAL " << endl;
        return con.find(data) != string::npos;
    }
};

class OrExpression: public Expression{
private:
    Expression* e1;
    Expression* e2;
public:
    OrExpression(Expression* e1, Expression* e2) {
        this->e1 = e1;
        this->e2 = e2;
    }
    bool intepretor(std::string con) {
        return  e1->intepretor(con) || e2->intepretor(con);
    }
    ~OrExpression() {
        delete e1;
        delete e2;
    }
};

class AndExpression : public Expression {
private:
    Expression* e1;
    Expression* e2;
public:
    AndExpression(Expression* e1, Expression* e2) {
        this->e1 = e1;
        this->e2 = e2;
    }
    bool intepretor(std::string con)  {
        return e1->intepretor(con) && e2->intepretor(con);
    }
    ~AndExpression() {
        delete e1;
        delete e2;
    }
};

int main() {

    Expression* e1 = new TerminalExpression("Adam");
    Expression* e2 = new TerminalExpression("Mary");

    Expression* orExpression = new OrExpression(e1, e2);
    cout << orExpression->intepretor("Mary") << endl;

    Expression* andExpression = new AndExpression(e1, e2);
    cout << andExpression->intepretor("Adam with Mary") << endl;

    return 0;
}