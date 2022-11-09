#ifndef COS214_OBSERVER_H
#define COS214_OBSERVER_H
#include "Directory.h"

class Observer {
public:
    virtual void update(std::list<Node*>* items) = 0;
};

#endif
