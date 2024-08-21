#ifndef COS214_DAIRYMILKBUBBLY_H
#define COS214_DAIRYMILKBUBBLY_H
#include "AeratedChocolate.h."

class DairyMilkBubbly: public AeratedChocolate { //PRODUCT SPECIALISATION
public:
    //DairyMilk costs 25.5, slab chosen in main
    DairyMilkBubbly(int bubblespccm)
            : AeratedChocolate("Cadbury", 20.35, bubblespccm) {}

};

#endif
