#pragma once
#include "AbstractionStack.h"

//Refined abstraction
class RA_HanoiStack: public AbstractionStack {
private:
    int peek() {
        //Hanoi stack has peek method (used in push)
        int value = stackData->pop();
        stackData->push(value);
        return value;
    }
public:
    RA_HanoiStack(ImplementationType i = ARRAY) : AbstractionStack(i) {}
    void push(int val) override {
        //Hanoi stack has own push method
        if (stackData->isEmpty() || val < peek()) {
            //can only push a smaller value, or onto empty stack

            //use the reference to the implementor to do the operation
            stackData->push(val);
        }
    }
    int pop() override {
        return stackData->pop();
    }
};
