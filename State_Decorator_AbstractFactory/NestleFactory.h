#ifndef COS214_NESTLEFACTORY_H
#define COS214_NESTLEFACTORY_H
#include "Confectionary.h"
#include "ConfectionaryFactory.h"
#include "MilkyBar.h"
#include "Aero.h"

class NestleFactory: public ConfectionaryFactory {public:
    virtual Confectionary* createRegular(bool slab) {
        return new MilkyBar(slab);
    };
    virtual Confectionary* createAerated(int bubblespccm){
        return new Aero(bubblespccm);
    }
};

#endif
