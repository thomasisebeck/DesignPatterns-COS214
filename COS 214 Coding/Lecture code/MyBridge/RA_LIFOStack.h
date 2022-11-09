#pragma once
#include "AbstractionStack.h"

//Refined abstraction
class RA_LIFOStack: public AbstractionStack {
public:
    RA_LIFOStack(ImplementationType i = ARRAY) : AbstractionStack(i) {}
    //No special implementation compared to abstract class
};
