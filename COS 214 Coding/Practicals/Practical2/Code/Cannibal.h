#ifndef COS214_CANNIBAL_H
#define COS214_CANNIBAL_H
#include "Enemy.h"

class Cannibal: public Enemy{
public:
    Cannibal(std::string attackMove, std::string defenceMove);
    virtual bool hitSquadMember (SquadMember* z);
    virtual void celebrate();
    virtual bool getHit (SquadMember* z);
    virtual void die();
};

#endif
