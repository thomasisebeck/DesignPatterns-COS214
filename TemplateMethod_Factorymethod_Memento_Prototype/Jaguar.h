#ifndef COS214_JAGUAR_H
#define COS214_JAGUAR_H
#include <string>
#include "Enemy.h"

class Jaguar: public Enemy {
public:
    Jaguar(std::string attackMove, std::string defenceMove);
    virtual bool hitSquadMember (SquadMember* z);
    virtual void celebrate();
    virtual bool getHit (SquadMember* z);
    virtual void die();
};

#endif
