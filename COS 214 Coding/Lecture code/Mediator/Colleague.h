#ifndef COS214_COLLEAGUE_H
#define COS214_COLLEAGUE_H
#include "Mediator.h"
#include <string>
class Colleague {
private:
    Mediator* mediator;
    static int id;
    int myId;
public:
    Colleague(Mediator* mediator) {
        this->mediator = mediator;
        myId = id++;
    }
    virtual void changed() = 0;
    int getID() { return myId; }
    virtual std::string get() = 0;
    virtual void set(std::string msg) = 0;
    ~Colleague() { delete mediator; }
};

int Colleague::id = 0;

#endif