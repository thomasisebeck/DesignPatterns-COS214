#include "CannibalFactory.h"
#include <string>
#include <iostream>
using namespace std;

CannibalFactory::CannibalFactory() : EnemyFactory(){}

Enemy* CannibalFactory::createEnemy(std::string attack, std::string defense) {
    Cannibal* cannibal = new Cannibal(attack, defense);

    //HP 30, 8 for cannibal, mul by 3 to make the game more fun
    cannibal->setHP(this->getUniformDist(8,30));
    //Damage for snake
    cannibal->setDamage(6);
    //set name
    cannibal->setName(this->getName());

    cout << "HP: " << cannibal->getHP() << endl;
    cout << "dmg: " << cannibal->getDamage() << endl;

    return cannibal;

}