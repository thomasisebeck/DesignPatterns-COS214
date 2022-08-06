#include "Enemy.h"
#include <string>
#include <iostream>
using namespace std;

Enemy::Enemy(int HP, int damage, string name, string primaryWeapon, string defenceMove) {
    this->HP = HP;
    this->damage = damage;
    this->name = name;
    this->primaryWeapon = primaryWeapon;
    this->defenceMove = defenceMove;
}

string Enemy::getName() { return name; }

void Enemy::setHP(int newHP) { this->HP = newHP; }

void Enemy::setDamage(int newDamage) { this->damage = newDamage; }

void Enemy::takeDamage(int attack) { this->HP -= attack; }

void Enemy::attack(SquadMember* z) {
    while (z->getHP() > 0 && this->getHP() > 0) {
        if (this->hitSquadMember(z)) {
            this->celebrate();
        }
        else if (this->getHit(z))
            this->die();
    }
}

std::string Enemy::getPrimaryWeapon(){ return this->primaryWeapon; }

std::string Enemy::getDefenceMove(){ return this->defenceMove; }

int Enemy::getHP(){ return this->HP; }

int Enemy::getDamage(){ return this->damage; }