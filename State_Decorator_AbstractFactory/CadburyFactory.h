#ifndef COS214_CADBURYFACTORY_H
#define COS214_CADBURYFACTORY_H
#include "Confectionary.h"
#include "ConfectionaryFactory.h"
#include "DairyMilk.h"
#include "DairyMilkBubbly.h"

class CadburyFactory: public ConfectionaryFactory {public:
    virtual Confectionary* createRegular(bool slab) {
        cout << "<< created Dairy Milk >>" << endl;
        return new DairyMilk(slab);
    };
    virtual Confectionary* createAerated(int bubblespccm) {
        cout << "<< created Dairy Milk Bubbly >>" << endl;
        return new DairyMilkBubbly(bubblespccm);
    }
};

#endif
