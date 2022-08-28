#ifndef COS214_DOESNOTEXIST_H
#define COS214_DOESNOTEXIST_H
#include "Chocolate.h"

class DoesNotExist: public Chocolate{
public:
    DoesNotExist(bool slab)
            : Chocolate("Nonexistent Product", 0.00, false) {}
};

#endif
