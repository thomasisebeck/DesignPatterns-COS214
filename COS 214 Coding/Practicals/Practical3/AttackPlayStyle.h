#ifndef COS214_ATTACKPLAYSTYLE_H
#define COS214_ATTACKPLAYSTYLE_H
#include "PlayStyle.h"
#include <string>

class AttackPlayStyle: public PlayStyle {
public:
    virtual std::string attack() {
        return "is attacking the opposing Pokemon.";
    }
};

#endif
