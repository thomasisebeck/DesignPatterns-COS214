#pragma once
#include <string>
#include <iostream>

class Player {
private:
    std::string task;
    std::string weapon;
public:
    Player(std::string w): weapon(w) {
        task = "No task assigned";
    }
    void setTask(std::string newTask) { this->task = newTask; }
    std::string getTask() { return task; }
    std::string getWeapon() { return weapon; }
    void setWeapon(std::string newWeapon) { this->weapon = newWeapon; }
    virtual void mission() = 0;
    virtual ~Player() = default;
};
