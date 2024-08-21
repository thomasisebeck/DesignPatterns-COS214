#include "Gorilla.h"
#include <iostream>
using namespace std;

Gorilla::Gorilla(string attackMove, string defenceMove)
        : Enemy(attackMove, defenceMove) {}

bool Gorilla::hitSquadMember(SquadMember *z) {
    cout << "Snake slams his fists on the ground, grows and hits " << z->getName()
         << " with " << this->getPrimaryWeapon() << "." << endl;

    z->takeDamage(this->getDamage());

    if (z->getHP() <= 0)
        return true;

    return false;
}

void Gorilla::celebrate() {
    cout  << "Player tried in vain trying to save himself." << endl;
}

bool Gorilla::getHit(SquadMember *z) {
    cout << "Roars and hits his chest in anger" << endl;

    // Same for all Enemies
    this->takeDamage(z->getDamage());
    if (this->getHP() <= 0)
        return true;

    return false;
}

void Gorilla::die() {
    cout << "The earth shakes as the gorilla falls to the ground" << endl;
}