#ifndef COS214_SNAKE_H
#define COS214_SNAKE_H
#include <string>
#include "Enemy.h"

class Snake : public Enemy {
public:
    Snake(std::string attackMove, std::string defenceMove);
    virtual bool hitSquadMember (SquadMember* z);
    virtual void celebrate();
    virtual bool getHit (SquadMember* z);
    virtual void die();
};


#endif
