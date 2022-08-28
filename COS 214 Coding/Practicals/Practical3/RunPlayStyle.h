#ifndef COS214_RUNPLAYSTYLE_H
#define COS214_RUNPLAYSTYLE_H
#include "PlayStyle.h"
#include <string>

class RunPlayStyle: public PlayStyle {
public:
    virtual std::string attack() {
        return "decides life is better than death and leaves the battle.";
    }
};

#endif
