#include "Enemy.h"
#include <string>
#include <iostream>
using namespace std;

Enemy::Enemy(string primaryWeapon, string defenceMove) {
    this->primaryWeapon = primaryWeapon;
    this->defenceMove = defenceMove;
}

Enemy::~Enemy() {}

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

string Enemy::getPrimaryWeapon(){ return this->primaryWeapon; }

string Enemy::getDefenceMove(){ return this->defenceMove; }

string Enemy::getName() { return this->name; }

void Enemy::setName(string name) { this->name = name; }

void Enemy::setHP(int newHP) { this->HP = newHP; }

int Enemy::getHP() const { return this->HP; }

int Enemy::getDamage() const { return this->damage; }