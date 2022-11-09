#ifndef COS214_ROBOT_H
#define COS214_ROBOT_H
#include <iostream>

class Robot {
private:
    bool isDead;
public:
    void makeDead() { this->isDead = true; }
    void makeAlive() { this->isDead = false; }
    void deadStatus() {
        if (this->isDead)
            std::cout << "I am dead!" << std::endl;
        else
            std::cout << "I am not dead!" << std::endl;
    }

};

#endif
