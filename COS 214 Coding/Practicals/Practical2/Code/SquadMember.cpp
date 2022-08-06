#include "SquadMember.h"
#include <string>
using namespace std;

SquadMember::SquadMember(int HP, int damage, string name) {
    this->HP = HP;
    this->damage = damage;
    this->name = name;
}

string SquadMember::getName() { return name; }

void SquadMember::setHP(int newHP) { this->HP = newHP; }

void SquadMember::setDamage(int newDamage) { this->damage = newDamage; }

int SquadMember::getHP() { return HP; }

void SquadMember::takeDamage(int attack) { this->HP -= attack; }

int SquadMember::getDamage() { return this->damage; }
