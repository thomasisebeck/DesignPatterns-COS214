#include "GorillaFactory.h"
#include <string>
using namespace std;

GorillaFactory::GorillaFactory() : EnemyFactory(){}

Enemy* GorillaFactory::createEnemy(std::string attack, std::string defense) {
    Gorilla* gorilla = new Gorilla(attack, defense);

    //HP 10,3 for jaguaruar
    gorilla->setHP(this->getUniformDist(4,12));
    //Damage for snake
    gorilla->setDamage(1);
    //set name
    gorilla->setName(this->getName());

    return gorilla;

}
