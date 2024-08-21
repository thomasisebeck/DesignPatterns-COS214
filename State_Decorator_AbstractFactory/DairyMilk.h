#ifndef COS214_DAIRYMILK_H
#define COS214_DAIRYMILK_H
#include "Chocolate.h"

class DairyMilk: public Chocolate { //PRODUCT SPECIALISATION
public:
    //DairyMilk costs 25.5, slab chosen in main
    DairyMilk(bool slab)
                : Chocolate("Cadbury", 25.2, slab) {}
};

#endif