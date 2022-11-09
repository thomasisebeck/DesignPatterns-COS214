#pragma once

//Implementor
//Interface for implementors

/*
 Defines primitive operations
 Abstract interface for higher level operations
 Overridden in concrete implementor
 */
class MyStackImplementor {
public:
    MyStackImplementor() {}
    virtual ~MyStackImplementor() {}
    virtual void push(int val) = 0;
    virtual int pop() = 0;
    virtual bool isEmpty() = 0;
    virtual bool isFull() = 0;
};
