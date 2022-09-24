#ifndef COS214_BACKUPORIGINATOR_H
#define COS214_BACKUPORIGINATOR_H
#include "Directory.h"
#include "BackupMemento.h"
#include "BackupCaretaker.h"

class BackupOriginator {
private:
    Directory* state;
public:
    void reinstantiateMemento(BackupMemento* memento) {
        state = memento->getState();
    }
    BackupMemento* createMemento() {
        return new BackupMemento(state);
    }
    Directory* getState() { return state; }
    void setState(Directory newState) { this->state = new Directory(newState); }
    void storeState(BackupCaretaker& care) { care.storeMemento(new BackupMemento(state)); }
};

#endif
