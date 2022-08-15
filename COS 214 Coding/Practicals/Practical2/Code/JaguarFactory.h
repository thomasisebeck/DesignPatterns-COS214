#ifndef COS214_JAGUARFACTORY_H
#define COS214_JAGUARFACTORY_H
#include "EnemyFactory.h"
#include "Jaguar.h"
#include <string>

class JaguarFactory: public EnemyFactory{
public:
    JaguarFactory();
    Enemy* createEnemy(std::string attack, std::string defense);
};

#endif
