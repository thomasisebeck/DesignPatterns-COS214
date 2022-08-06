#ifndef CALCULATOR_H
#define CALCULATOR_H

template<typename T>
class Calculator {
private:
    T num1, num2;
public:
    Calculator(T n1, T n2);
    int add();
    int subtract();
    int multiply();
    int divide();
};

#endif //CALCULATOR_H
