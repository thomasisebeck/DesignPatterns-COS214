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
        auto* newMemento = new NavigatorMemento(node);
        list.push_front(newMemento);
    }

};

#endif
