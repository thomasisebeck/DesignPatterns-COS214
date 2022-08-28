#ifndef COS214_NORMALBATTLESTATE_H
#define COS214_NORMALBATTLESTATE_H
#include "BattleState.h"
#include <iostream>

class NormalBattleState: public BattleState {
private:
    int damage;
public:
    NormalBattleState() { this->battleStyle = "normal"; }
    virtual void handle(std::string name, int damage){
        this->damage = damage;
        std::cout   << name
                    << " has no special state, normal battle attack will deal "
                    << this->getStateDamage()
                    << " points."
                    << std::endl;
    }
    virtual int getStateDamage() { return this->damage; }
};

#endif