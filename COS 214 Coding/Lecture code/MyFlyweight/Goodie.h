#pragma  once
#include "Player.h"
#include <iostream>

class Goodie: public Player {
public:
    Goodie(std::string w, std::string t) : Player(w){
        this->setTask(t);
        std::cout << "Created Goodie with task " << t << " and weapon " << w << "."  << std::endl;
    }
    virtual void mission() {
        std::cout << "GOODIE " << this->getTask() << " with weapon " << this->getWeapon() << std::endl;
    }
    virtual ~Goodie() = default;
};