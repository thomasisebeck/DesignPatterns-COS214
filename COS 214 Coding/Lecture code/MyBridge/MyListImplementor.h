#pragma once
#include "MyStackImplementor.h"
#include <list>

//independent interface
//to implement the stack as a list

class MyListImplementor: public MyStackImplementor {
private:
    struct Node {
        int data;
        Node* next;
    };
    Node* head;
public:
    MyListImplementor() {
        this->head = nullptr;
    }
    ~MyListImplementor() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    virtual void push(int val) {
        Node* newNode = new Node;
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }
    virtual int pop() {
        if (isEmpty())
            return 0;

        Node* temp = head;
        head = head->next;
        int data = temp->data;
        delete temp;

        return data;
    }
    virtual bool isEmpty() {
        return head == nullptr;
    }
    virtual bool isFull() {
        return false;
    }
};
