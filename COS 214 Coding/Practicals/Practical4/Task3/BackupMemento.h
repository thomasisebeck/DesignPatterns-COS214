#ifndef COS214_BACKUPMEMENTO_H
#define COS214_BACKUPMEMENTO_H
#include "Directory.h"
#include "BackupOriginator.h"

class BackupOriginator;

class BackupMemento {
private:
    friend class BackupOriginator;
    Directory* state;

    //set state in constructor
    BackupMemento(Directory* newState) { this->state = newState; }
    Directory* getState() { return state; }
public:
    virtual ~BackupMemento() {
        delete state;
        state = nullptr;
    }
};

#endif
