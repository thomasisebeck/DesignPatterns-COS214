#ifndef COS214_CONCRETEOBSERVER_H
#define COS214_CONCRETEOBSERVER_H
#include "Observer.h"
#include "Directory.h"
#include "Node.h"

class ConcreteObserver: public Observer {
private:
    Directory* subject;
public:
    ConcreteObserver(Directory* subject) {
        this->subject = subject;
    }
    virtual void update() {
        //get the files
        std::list<Node*> items = subject->items;

        //see if there is a virus
        std::list<Node*>::iterator it;

        for (it = items.begin(); it != items.end(); it++)
            if ((*it)->getName() == "virus")
                cout << "<< ALERT VIRUS DETECTED! >>" << endl;
    }
};

#endif
