#include "EnemyFactory.h"
#include <cstdlib>
#include <ctime>
#include <random>
using namespace std;

std::string EnemyFactory::getName() {
    string names[10] = {
            "Blackout",
            "Shivers",
            "Angel Slayer",
            "Crypto",
            "Flatline",
            "Flux",
            "Burnout",
            "Nocturne",
            "Surge",
            "Crossfire"
    };

    srand(time(NULL));
    int index = rand() % 10;
    return names[index];
}

EnemyFactory::EnemyFactory() {}
EnemyFactory::~EnemyFactory() {}

int EnemyFactory::getNormalDist(int mean, int stdDev) {
    normal_distribution<double> distribution(mean,stdDev);
    random_device rand;
    mt19937 gen(rand());

    return trunc(distribution(gen));
}

int EnemyFactory::getUniformDist(int a, int b) {
    std::uniform_int_distribution<int> distribution(a,b);
    std::default_random_engine gen;

    return distribution(gen);
}
