#ifndef COS214_BACKUPORIGINATOR_H
#define COS214_BACKUPORIGINATOR_H
#include "Directory.h"
#include "BackupMemento.h"
#include "BackupCaretaker.h"

class BackupOriginator {
private:
    Directory* state;
public:
    BackupOriginator() { state = nullptr; }
    ~BackupOriginator() { delete state; }
    BackupMemento* getMemento() { return new BackupMemento(state); }
    Directory* getState() { return state; }
    void setState(Directory* newState) {
        if (state != nullptr)
            delete state;
        state = new Directory(*newState);
    }

    void storeState(BackupCaretaker& care) {
        care.storeMemento(new BackupMemento(state));
    }
    bool reinstantiateMemento(BackupMemento* memento) {
        memento->getState()->listItems(0, true);

        if (memento->getState() == nullptr)
            return false;

        Directory* temp = memento->getState();

        if (temp != nullptr) {
            state = new Directory(*memento->getState());
            return true;
        }

        return false;
    }

};

#endif
