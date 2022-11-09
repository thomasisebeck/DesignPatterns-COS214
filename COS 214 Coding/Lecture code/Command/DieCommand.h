#ifndef COS214_DIECOMMAND_H
#define COS214_DIECOMMAND_H
#include "Command.h"
#include <iostream>

class DieCommand: public Command {
private:
    Robot* myRobot;
public:
    friend class Robot;
    DieCommand(Robot* myRobot) { this->myRobot = myRobot; }
    void execute() {
        this->myRobot->makeDead();
        this->myRobot->deadStatus();
    }
};


#endif
