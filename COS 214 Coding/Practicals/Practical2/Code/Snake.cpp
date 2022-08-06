#include "Snake.h"
#include <iostream>
using namespace std;

Snake::Snake(int HP, int damage, string name, string attackMove, string defenceMove)
        : Enemy(HP, damage, name, attackMove, defenceMove) {}

bool Snake::hitSquadMember(SquadMember *z) {
    cout << "Snake wraps around " << z->getName()
        << " and uses " << this->getPrimaryWeapon() << "." << endl;

    z->takeDamage(this->getDamage());

    if (z->getHP() <= 0)
        return true;

    return false;
}

void Snake::celebrate() {
    cout  << "Player tried strongly till the end." << endl;
}

bool Snake::getHit(SquadMember *z) {
    cout << "Slithers rapidly searching for safety and employs "
        << this->getDefenceMove() << "." << endl;

    // Same for all Enemies
    this->setHP(this->getHP() - z->getDamage());
    if (this->getHP() <= 0)
        return true;

    return false;
}

void Snake::die() {
    cout << "Hisses and curls up as he is defeated." << endl;
}