#ifndef COS214_AERO_H
#define COS214_AERO_H
#include "AeratedChocolate.h."

class Aero: public AeratedChocolate { //PRODUCT SPECIALISATION
public:
    //DairyMilk costs 25.5, slab chosen in main
    Aero(int bubblespccm)
            : AeratedChocolate("Nestle", 27.12, bubblespccm) {}

};

#endif
