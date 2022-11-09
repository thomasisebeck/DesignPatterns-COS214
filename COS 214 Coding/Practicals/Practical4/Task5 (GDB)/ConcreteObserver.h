#ifndef COS214_CONCRETEOBSERVER_H
#define COS214_CONCRETEOBSERVER_H
#include "Observer.h"

class ConcreteObserver: public Observer {
public:
    ConcreteObserver() {}

    virtual void update(std::list<Node*>* items) {
        //tell the stubject to update

        //see if there is a virus
        std::list<Node*>::iterator it;

        for (it = items->begin(); it != items->end(); it++)
            if ((*it)->getName() == "virus")
                cout << "<< ALERT VIRUS DETECTED! >>" << endl;
    }
};

#endif
