#ifndef COS214_NAVIGATORMEMENTO_H
#define COS214_NAVIGATORMEMENTO_H
#include "Directory.h"
#include <list>

class NavigatorMemento {
private:
    std::list<Directory*> list;
public:
    Directory* getLastNode() {
        if (list.size() == 0)
            return nullptr;

        Directory* front = list.front();
        list.pop_front();

        /*cout << "popping front: " << endl;
        this->print();*/

        return front;
    }

    void addNode(Directory* node) {
        list.push_front(node);
    }

    void print() {

        cout << "[";
        for (Directory* dir : list)
            cout << " " <<  dir->getName() << " ";

        cout << "]" << endl;
    }
};

#endif
