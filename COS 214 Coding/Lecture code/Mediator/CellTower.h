#ifndef COS214_CELLTOWER_H
#define COS214_CELLTOWER_H
#include "Mediator.h"
#include <list>

class CellTower: public Mediator { //conc mediator
private:
    std::list<Colleague> myColleagues;
public:
    CellTower() : Mediator() {}
    void sendMessage(Colleague *who, std::string msg) {
        std::list<Colleague>::iterator iter;
        for (iter = myColleagues.begin(); iter != myColleagues.end(); iter++)
            if (iter->getID() == who->getID()) {
                who->set(msg);
                notify(who);
            }
    }
    void broadcastMessage(std::string msg) {
        std::list<Colleague>::iterator iter;
        for (iter = myColleagues.begin(); iter != myColleagues.end(); iter++) {
            (*iter).set(msg);
            (*iter).changed();
        }
    }
    virtual void notify(Colleague* who) {
        who->changed();
    }
};

#endif
