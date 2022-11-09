#pragma once
#include "AbstractionStack.h"
#include <iostream>
using namespace std;

class RA_WackStack : public AbstractionStack {
    RA_WackStack(ImplementationType i = ARRAY) : AbstractionStack(i) {}
    int pop() override {
        //pop 2 times
        int throwAway = this->stackData->pop();
        int ret = this->stackData->pop();

        cout << "Throw away: " << throwAway << endl;
        return ret;
    }
};
