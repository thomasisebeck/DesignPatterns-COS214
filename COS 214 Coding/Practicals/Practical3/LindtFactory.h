#ifndef COS214_LINDT_H
#define COS214_LINDT_H
#include "ConfectionaryFactory.h"
#include "Lindor.h"
#include "DoesNotExist.h"
#include <iostream>

class LindtFactory: public ConfectionaryFactory {
public:
    virtual Confectionary* createRegular(bool slab) {
        cout << "<< created Lindor >>" << endl;
        return new Lindor(slab);
    };
    virtual Confectionary* createAerated(int bubblespccm){
        std::cout << "We do not offer an aerated lindor product" << std::endl;
        return new DoesNotExist(false);
    }
};

#endif
