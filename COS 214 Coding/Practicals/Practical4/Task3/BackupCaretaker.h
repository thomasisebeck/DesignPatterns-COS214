#ifndef COS214_BACKUPCARETAKER_H
#define COS214_BACKUPCARETAKER_H
#include "BackupMemento.h"

class BackupCaretaker {
private:
    BackupMemento* mem;
public:
    void storeMemento(BackupMemento* mem) {
        this->mem = mem;
    }
    BackupMemento* retrieveMemento() { return this->mem; }
    ~BackupCaretaker() { delete this->mem; }
};

#endif
