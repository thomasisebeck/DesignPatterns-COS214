#ifndef COS214_STRONGBATTLESTATE_H
#define COS214_STRONGBATTLESTATE_H
#include "BattleState.h"
#include <iostream>

class StrongBattleState: public BattleState {
private:
    int damage;
public:
    StrongBattleState() { this->battleStyle = "strong"; }
    virtual void handle(std::string name, int damage){
        this->damage = damage;
        std::cout   << name
                    << " has selected a strong battle state and will inflict "
                    << this->getStateDamage()
                    << " points."
                    << std::endl;
    }
    int getStateDamage() { return damage * 2; }
};

#endif
