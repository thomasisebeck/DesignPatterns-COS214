#ifndef COS214_ROOT_H
#define COS214_ROOT_H
#include "Directory.h"
#include "BackupMemento.h"
#include "BackupCaretaker.h"

class Root: public Directory {
private:
    BackupOriginator* originator;
    BackupCaretaker* caretaker;
    Root(Directory* oldRoot) : Directory(*oldRoot) {}  //copy constructor used to reinstantiate
public:
    Root() : Directory("root", true) {
        originator = new BackupOriginator;
        caretaker = new BackupCaretaker;
    }
    void backup() {
        originator->setState(this);
        originator->storeState(*caretaker);
    }
    void restore() {
        originator->reinstantiateMemento(caretaker->retrieveMemento());
        Root(originator->getState()); //copy the new state to the root!
    }
    ~Root(){
        delete originator;
        delete caretaker;
    }
};

#endif //COS214_ROOT_H
