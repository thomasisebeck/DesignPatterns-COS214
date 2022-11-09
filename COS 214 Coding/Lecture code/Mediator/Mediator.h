#ifndef COS214_MEDIATOR_H
#define COS214_MEDIATOR_H
#include "Colleague.h"

class Mediator {
public:
    virtual void notify(Colleague* who) = 0;
};

#endif
