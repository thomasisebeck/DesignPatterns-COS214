#ifndef COS214_COMMAND_H
#define COS214_COMMAND_H
#include "Robot.h"

class Command {
public:
    virtual void execute() = 0;
};

#endif