#ifndef COS214_NAVIGATORMEMENTO_H
#define COS214_NAVIGATORMEMENTO_H
#include "Directory.h"
#include <list>

class NavigatorMemento {
private:
    std::list<Directory*> list;
public:
    Directory* getLastNode() {
        if (list.empty()) {
            cout << "list is empty! " << endl;
            return nullptr;
        }

        this->print();

        Directory* front = list.front();

        cout << "Retrieved: " << front->getName() << endl;

        list.pop_front();

        this->print();

        return front;
    }

    void addNode(Directory* node) {
        cout << "pushing : " << node->getName() << endl;
        list.push_back(node);

        this->print();
    }

    void print() {
        for (Directory* dir : list)
            cout << dir->getName() << endl;

        cout << " ------------ " << endl;
    }
};

#endif
