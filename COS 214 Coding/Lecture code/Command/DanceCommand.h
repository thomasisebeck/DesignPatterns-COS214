#ifndef COS214_DANCECOMMAND_H
#define COS214_DANCECOMMAND_H
#include "Command.h"
#include <iostream>

class DanceCommand: public Command {
private:
    Robot* myRobot;
public:
    DanceCommand(Robot* myRobot) { this->myRobot = myRobot; }
    void execute() {
        std::cout << "I am dancing!!!" << std::endl;
    }
};

#endif
