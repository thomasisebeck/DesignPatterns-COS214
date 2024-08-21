#include "SnakeFactory.h"
#include <string>
using namespace std;

SnakeFactory::SnakeFactory() : EnemyFactory(){}

Enemy* SnakeFactory::createEnemy(std::string attack, std::string defense) {
    Snake* snake = new Snake(attack, defense);

    //HP 6,1 for snake
    snake->setHP(this->getNormalDist(6,1));
    //Damage for snake
    snake->setDamage(2);
    //set name
    snake->setName(this->getName());

    return snake;
}

