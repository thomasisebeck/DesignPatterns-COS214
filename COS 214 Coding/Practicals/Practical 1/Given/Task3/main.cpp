#include "Calculator.h"
#include "Calculator.cpp"
#include <iostream>
using namespace std;

int main() {

    Calculator<string> c("Hello","World");

    cout << c.multiply() << endl;

    return 0;
}