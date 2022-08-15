#ifndef COS214_STATECARE_H
#define COS214_STATECARE_H

#include "SaveState.h"

class StateCare { //caretaker
private:
    SaveState* state;
public:
    StateCare() {}
    SaveState* getMemento() { return state; }
    void setMemento(SaveState* state) { this->state = state; }
};


#endif
