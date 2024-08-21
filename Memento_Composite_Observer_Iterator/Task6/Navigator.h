#ifndef COS214_NAVIGATOR_H
#define COS214_NAVIGATOR_H
#include "Directory.h"
#include "NavigatorMemento.h"
#include <list>

//originator & caretaker of the navMemento
class Navigator {
private:
    std::list<NavigatorMemento*> list;
public:
    Directory* getLastNode() {
        if (list.size() == 0)
            return nullptr;

        NavigatorMemento* front = list.front();
        list.pop_front();

        return front->getState();
    }

    void addNode(Directory* node) {
        list.push_front(new NavigatorMemento(node));
    }

    ~Navigator() {
        /*std::list<NavigatorMemento*>::iterator  iter;
        for (iter = list.begin(); iter != list.end(); iter++)
            delete (*iter);*/

        while (!list.empty()) {
            NavigatorMemento* temp = list.back();
            list.pop_back();
            delete temp;
        }

        list.clear();
    }

};

#endif
