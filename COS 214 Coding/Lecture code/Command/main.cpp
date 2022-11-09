#include <iostream>
#include "Robot.h"
#include "DanceCommand.h"
#include "DieCommand.h"
#include "ReviveCommand.h"
#include "Remote.h"
using namespace std;

int main() {

    Robot* myRobot = new Robot;
    DieCommand* die = new DieCommand(myRobot);
    DanceCommand* dance = new DanceCommand(myRobot);
    ReviveCommand* revive = new ReviveCommand(myRobot);
    Remote* remote = new Remote(dance, die, revive);

    int input = 0;

    while (true) {
        cout << "Enter command (1. Dance, 2. Die, 3. Revive)" << endl;
        cin >> input;
        if (input == -1)
            return 0;
        switch (input) {
            case 1:
                remote->makeDance();
                break;
            case 2:
                remote->makeDie();
                break;
            case 3:
                remote->makeRevive();
        }

    }

    return 0;
}