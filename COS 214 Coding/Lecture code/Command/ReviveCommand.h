#ifndef COS214_REVIVECOMMAND_H
#define COS214_REVIVECOMMAND_H
#include "Command.h"
#include <iostream>

class ReviveCommand: public Command {
private:
    Robot* myRobot;
public:
    ReviveCommand(Robot* myRobot) { this->myRobot = myRobot; }
    void execute() {
        this->myRobot->makeAlive();
        this->myRobot->deadStatus();
    }
};
#endif
