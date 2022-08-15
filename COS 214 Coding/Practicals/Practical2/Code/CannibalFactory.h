#ifndef COS214_CANNIBALFACTORY_H
#define COS214_CANNIBALFACTORY_H
#include "EnemyFactory.h"
#include "Cannibal.h"
#include <string>

class CannibalFactory: public EnemyFactory {
public:
    CannibalFactory();
    Enemy* createEnemy(std::string attack, std::string defense);
};

#endif
