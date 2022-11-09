#pragma once
#include "MyStackImplementor.h"
#include "MyArrayImplementor.h"
#include "MyListImplementor.h"

//Abstraction
/* Defines abstraction's interface
 * Maintains reference to obj of type implementor */

enum ImplementationType { ARRAY, LIST }; //stack impl as arr or list

class AbstractionStack {
public:

    AbstractionStack(ImplementationType type = ARRAY) {
        //Create the stack data depending on the implementation
        switch (type) {
            case ARRAY:
                stackData = new MyArrayImplementor();
                break;
            case LIST:
                stackData = new MyListImplementor();
                break;
        }
    }

    virtual ~AbstractionStack() {
        delete stackData;
    };

    virtual void push(int val) {
        stackData->push(val);
    };
    virtual int pop() {
        return stackData->pop();
    }
    virtual bool isEmpty() {
        return stackData->isEmpty();
    }
    virtual bool isFull() {
        return stackData->isFull();
    }

protected:
    //reference to implementor
    //used to peform operations
    MyStackImplementor* stackData;
    //This implementor can be a list or an array implementor
};
