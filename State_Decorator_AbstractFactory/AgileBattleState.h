#ifndef COS214_AGILEBATTLESTATE_H
#define COS214_AGILEBATTLESTATE_H
#include "BattleState.h"
#include <iostream>
#include <cmath>

class AgileBattleState: public BattleState {
private:
    int damage;
public:
    AgileBattleState() { this->battleStyle = "agile"; }
    virtual void handle(std::string name, int damage){
        this->damage = damage;
        std::cout   << name
                    << " has selected an agile battle state and is allowed two battle attacks in one turn and will deal "
                    << this->getStateDamage()
                    << " points."
                    << std::endl;
    }
    virtual int getStateDamage() { return (int) ceil(damage / 4.00) * 3; }
};

#endif
