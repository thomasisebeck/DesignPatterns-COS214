#ifndef COS214_MILKYBAR_H
#define COS214_MILKYBAR_H
#include "Chocolate.h"

class MilkyBar: public Chocolate { //PRODUCT SPECIALISATION
public:
    //MilkyBar costs 19.5, slab chosen in main
    MilkyBar(bool slab)
            : Chocolate("Nestle", 19.50, slab) {}
};


#endif
