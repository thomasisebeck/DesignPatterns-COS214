﻿#ifndef COS214_BACKUPCARETAKER_H
#define COS214_BACKUPCARETAKER_H
#include "BackupMemento.h"

class BackupCaretaker {
private:
    BackupMemento* mem;
public:
    BackupCaretaker() { this->mem = nullptr;  }
    void storeMemento(BackupMemento* mem) { this->mem = mem; }
    BackupMemento* retrieveMemento() {  return this->mem;  }
    void deleteMemento() {
        delete this->mem;
        this->mem = nullptr;
    }
    ~BackupCaretaker() { delete this->mem; }
};

#endif
