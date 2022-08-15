#ifndef COS214_SNAKEFACTORY_H
#define COS214_SNAKEFACTORY_H
#include "EnemyFactory.h"
#include "Snake.h"
#include <string>

class SnakeFactory: public EnemyFactory {
public:
    SnakeFactory();
    Enemy* createEnemy(std::string attack, std::string defense);
};

#endif
