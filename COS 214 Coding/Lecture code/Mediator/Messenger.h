#ifndef COS214_MESSENGER_H
#define COS214_MESSENGER_H
#include "Colleague.h"
#include <iostream>

class Messenger: public Colleague {
private:
    std::string id;
    std::string msg;
public:
    Messenger(Mediator* myMediator, std::string id) : Colleague(myMediator){
        this->id = id;
        this->msg = "[empty]";
    }
    virtual void changed() {
        std::cout << "[" << id << "]: recieved '" << this->msg << "'" << std::endl;
    }
    std::string getId() { return id; }
    std::string get() { return this->msg; }
    void set(std::string msg) { this->msg = msg; }
};

#endif
