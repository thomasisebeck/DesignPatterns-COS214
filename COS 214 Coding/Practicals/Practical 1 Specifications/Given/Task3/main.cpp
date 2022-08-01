#include "Calculator.h"
#include "Calculator.cpp"
#include <iostream>
using namespace std;

int main() {

    Calculator<int> c(3,4);

    cout << c.add() << endl;
    cout << c.subtract() << endl;
    cout << c.divide() << endl;
    cout << c.multiply() << endl;

    return 0;
}