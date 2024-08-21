#include "Cannibal.h"
#include <iostream>
using namespace std;

Cannibal::Cannibal(string attackMove, string defenceMove)
        : Enemy(attackMove, defenceMove) {}

bool Cannibal::hitSquadMember(SquadMember *z) {
    cout << "Cannibal rushes towards " << z->getName()
         << " with a " << this->getPrimaryWeapon() << "." << endl;

    z->takeDamage(this->getDamage());

    if (z->getHP() <= 0)
        return true;

    return false;
}

void Cannibal::celebrate() {
    cout  << "Screams with his last breath, 'I am your father'." << endl;
}

bool Cannibal::getHit(SquadMember *z) {
    cout << "The other villagers come running deploying "
         << this->getDefenceMove() << "." << endl;

    // Same for all Enemies
    this->takeDamage(z->getDamage());
    if (this->getHP() <= 0)
        return true;

    return false;
}

void Cannibal::die() {
    cout << "Shakes his " << this->getPrimaryWeapon() << " at the player's remains." << endl;
}
