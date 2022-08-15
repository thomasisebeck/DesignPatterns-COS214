#include "Jaguar.h"
#include <iostream>
using namespace std;

Jaguar::Jaguar(string attackMove, string defenceMove)
        : Enemy(attackMove, defenceMove) {}

bool Jaguar::hitSquadMember(SquadMember *z) {
    cout << "Jaguar leaps toward the " << z->getName()
         << " and delivers a forceful " << this->getPrimaryWeapon() << "." << endl;

    z->takeDamage(this->getDamage());

    if (z->getHP() <= 0)
        return true;

    return false;
}

void Jaguar::celebrate() {
    cout  << "Should have fought harder soldier." << endl;
}

bool Jaguar::getHit(SquadMember *z) {
    cout << "Grows in pain as he is maimed. Jaguar turns around and delivers "
         << this->getDefenceMove() << " against " << z->getName() << "." << endl;

    // Same for all Enemies
    this->takeDamage(z->getDamage());
    if (this->getHP() <= 0)
        return true;

    return false;
}

void Jaguar::die() {
    cout << "Gives one last growl before falling over." << endl;
}