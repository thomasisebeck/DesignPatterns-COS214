#include "JaguarFactory.h"
#include <string>
using namespace std;

JaguarFactory::JaguarFactory() : EnemyFactory(){}

Enemy* JaguarFactory::createEnemy(std::string attack, std::string defense) {
    Jaguar* jaguar = new Jaguar(attack, defense);

    //HP 10,3 for jaguaruar
    jaguar->setHP(this->getNormalDist(10,3));
    //Damage for snake
    jaguar->setDamage(4);
    //set name
    jaguar->setName(this->getName());

    return jaguar;

}