#ifndef COS214_NODEITERATOR_H
#define COS214_NODEITERATOR_H
#include <list>
#include <iostream>
#include <list>
using namespace std;

class Directory;

class NodeIterator {
    friend class Directory;
public:
    NodeIterator* operator++() {
        curr = ++curr;
        return this;
    }
    bool operator==(const Node* compare) const {
        return (compare == (*curr));
    }
    NodeIterator first() {
        curr = myList.begin();
        return (*this);
    }
    bool hasNext() {
        return (!myList.empty() && curr != myList.end());
    }
    Node* current() {
        if (myList.empty()) return nullptr;
        return (*curr);
    }
protected:
    NodeIterator(list<Node*>& passList){
        this->myList = passList;
        if (this->myList.empty())
            curr = myList.end();
        else
            curr = myList.begin(); //ref to first member
    }
private:
    list<Node*> myList;
    std::list<Node*>::iterator curr;
};
#endif
