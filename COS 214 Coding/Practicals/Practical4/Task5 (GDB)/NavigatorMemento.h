#ifndef COS214_NAVIGATORMEMENTO_H
#define COS214_NAVIGATORMEMENTO_H
#include "Directory.h"

class NavigatorMemento {
private:
    Directory* state;
public:
    NavigatorMemento(Directory* state) {
        this->state = state;
    }
    Directory* getState() { return state; }
    ~NavigatorMemento() {
        delete state;
    }
};

#endif
