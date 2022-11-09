#pragma once
#include "MyStackImplementor.h"

class MyArrayImplementor: public MyStackImplementor {
private:
    int* items;
    int currentItem;
    int size;
public:
    MyArrayImplementor(int size = 10) {
        items = new int[size];
        this->size = size;
        this->currentItem = 0;
    }
    virtual void push(int val) {
        currentItem++;
        if (!isFull())
            items[currentItem] = val;
    }
    virtual int pop() {
        if (this->currentItem == 0)
            return -1;
        return items[currentItem--];
    }
    virtual bool isEmpty() {
        return currentItem == 0;
    }
    virtual bool isFull() {
        return currentItem == size;
    }
    virtual ~MyArrayImplementor() {
        delete [] items;
    }
};
