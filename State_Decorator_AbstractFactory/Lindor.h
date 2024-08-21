#ifndef COS214_LINDOR_H
#define COS214_LINDOR_H
#include "Chocolate.h"

class Lindor: public Chocolate { //PRODUCT SPECIALISATION
public:
    //Lindor costs 30.45, slab chosen in main
    Lindor(bool slab)
            : Chocolate("Lindt", 30.45, slab) {}
};

#endif