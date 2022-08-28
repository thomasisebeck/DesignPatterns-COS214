#ifndef COS214_CONFECTIONARYFACTORY_H
#define COS214_CONFECTIONARYFACTORY_H
#include "Confectionary.h"

class ConfectionaryFactory {
public:
    virtual Confectionary* createRegular(bool slab) = 0;
    virtual Confectionary* createAerated(int bubblespccm) = 0;
    virtual ~ConfectionaryFactory()= default;
};

#endif
