#ifndef COS214_BATTLESTATECONTEXT_H
#define COS214_BATTLESTATECONTEXT_H
#include "BattleState.h"

class BattleStateContext {
private:
    BattleState* state;
    std::string name;
    int damage;
public:
    BattleStateContext(BattleState* initialState, std::string name, int damage) {
        this->state = initialState;
        this->name = name;
        this->damage = damage;
    }
    void cycle() { state->handle(name, damage); }
    void setState(BattleState* state) { this->state = state; }
    ~BattleStateContext() { delete state; }
protected:
    BattleState* getState() { return state; }
};

#endif
