#ifndef COS214_ENEMY_H
#define COS214_ENEMY_H

#include "SquadMember.h"

class Enemy {
private:
    int HP;
    int damage;
    std::string name;
    std::string primaryWeapon;
    std::string defenceMove;
public:
    Enemy(int HP, int damage, std::string name, std::string primaryWeapon, std::string defenceMove);
    void setDamage(int newDamage);
    std::string getName();
    void setHP(int newHP);
    void attack(SquadMember* z);
    void takeDamage(int attack);
    std::string getPrimaryWeapon();
    std::string getDefenceMove();
    int getHP();
    int getDamage();

    virtual bool hitSquadMember (SquadMember* z) = 0;
    virtual void celebrate() = 0;
    virtual bool getHit (SquadMember* z) = 0;
    virtual void die() = 0;
};

#endif
