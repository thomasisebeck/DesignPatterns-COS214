#pragma  once
#include "Player.h"
#include <iostream>

class Terrorist: public Player {
public:
    Terrorist(std::string w, std::string t) : Player(w){
        this->setTask(t);
        std::cout << "Created Terrorist with task " << t << " and weapon " << w << "."  << std::endl;
    }
    virtual void mission() {
        std::cout << "TERRORIST " << this->getTask() << " with weapon " << this->getWeapon() << std::endl;
    }
    virtual ~Terrorist() = default;
};