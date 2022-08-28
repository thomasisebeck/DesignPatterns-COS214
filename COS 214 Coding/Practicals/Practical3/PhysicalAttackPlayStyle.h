#ifndef COS214_PHYSICALATTACKPLAYSTYLE_H
#define COS214_PHYSICALATTACKPLAYSTYLE_H
#include "PlayStyle.h"
#include <string>

class PhysicalAttackPlayStyle: public PlayStyle {
public:
    virtual std::string attack() {
        return "is using physical ability to attack.";
    }
};


#endif
