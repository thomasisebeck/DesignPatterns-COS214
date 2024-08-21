#ifndef COS214_GORILLA_H
#define COS214_GORILLA_H
#include "Enemy.h"

class Gorilla: public Enemy{
public:
    Gorilla(std::string attackMove, std::string defenceMove);
    virtual bool hitSquadMember (SquadMember* z);
    virtual void celebrate();
    virtual bool getHit (SquadMember* z);
    virtual void die();
};

#endif
