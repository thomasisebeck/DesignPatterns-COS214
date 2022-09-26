#ifndef COS214_BACKUPMEMENTO_H
#define COS214_BACKUPMEMENTO_H
#include "Directory.h"
#include "BackupOriginator.h"

class BackupOriginator;

class BackupMemento {
private:
    friend class BackupOriginator;
    friend class Root; //origninator
    Directory* state;

    //set state in constructor
    BackupMemento(Directory* newState) { this->state = newState; }

public:
    //make private!!!!
    Directory* getState() { return state; }

    virtual ~BackupMemento() {
        delete state;
        state = nullptr;
    }
};

#endif
