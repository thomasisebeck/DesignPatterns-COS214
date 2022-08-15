#ifndef COS214_GORILLAFACTORY_H
#define COS214_GORILLAFACTORY_H
#include "EnemyFactory.h"
#include "Gorilla.h"
#include <string>

class GorillaFactory: public EnemyFactory {
public:
    GorillaFactory();
    Enemy* createEnemy(std::string attack, std::string defense);
};


#endif
