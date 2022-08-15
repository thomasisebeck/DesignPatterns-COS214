#include "SquadMember.h"
#include <string>
using namespace std;

SquadMember::SquadMember(int HP, int damage, string name) {
    this->HP = HP;
    this->damage = damage;
    this->name = name;
}

string SquadMember::getName() const { return name; }

void SquadMember::setHP(int newHP) { this->HP = newHP; }

void SquadMember::setDamage(int newDamage) { this->damage = newDamage; }

int SquadMember::getHP() const { return HP; }

void SquadMember::takeDamage(int attack) { this->HP -= attack; }

int SquadMember::getDamage() const { return this->damage; }

SquadMember* SquadMember::clone(std::string newName) const {
    return new SquadMember(this->HP, this->damage, newName);
}
