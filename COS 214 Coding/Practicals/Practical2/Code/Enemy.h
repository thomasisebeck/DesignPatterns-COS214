#ifndef COS214_ENEMY_H
#define COS214_ENEMY_H

#include "SquadMember.h"

class Enemy {
private:
    int HP;
    int damage;
    std::string primaryWeapon;
    std::string defenceMove;
    std::string name;
public:
    Enemy(std::string primaryWeapon, std::string defenceMove);
    virtual ~Enemy();
    void setDamage(int newDamage);
    void attack(SquadMember* z);
    void takeDamage(int attack);
    std::string getPrimaryWeapon();
    std::string getDefenceMove();
    std::string getName();
    void setName(std::string name);
    void setHP(int newHP);
    int getHP() const;
    int getDamage() const;

    virtual bool hitSquadMember (SquadMember* z) = 0;
    virtual void celebrate() = 0;
    virtual bool getHit (SquadMember* z) = 0;
    virtual void die() = 0;
};

#endif
