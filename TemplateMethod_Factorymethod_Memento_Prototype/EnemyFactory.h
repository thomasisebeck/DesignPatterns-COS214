#ifndef COS214_ENEMYFACTORY_H
#define COS214_ENEMYFACTORY_H
#include <string>
#include "Enemy.h"

class EnemyFactory {
protected:
    std::string getName();
public:
    EnemyFactory();
    virtual ~EnemyFactory();
    virtual Enemy* createEnemy(std::string attack, std::string defense) = 0;
    int getNormalDist(int mean, int stdDev);
    int getUniformDist(int a, int b);
};


#endif
