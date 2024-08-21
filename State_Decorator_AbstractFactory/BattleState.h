#ifndef COS214_BATTLESTATE_H
#define COS214_BATTLESTATE_H
#include <string>

class BattleState { //state
protected:
    std::string battleStyle;
public:
    virtual void handle(std::string name, int damage) = 0;
    virtual std::string getBattleStyle() {  return this->battleStyle;  }
    virtual int getStateDamage() = 0;
    virtual ~BattleState() = default;
};

#endif
