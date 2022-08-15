#ifndef COS214_SAVESTATE_H
#define COS214_SAVESTATE_H

#include "SquadMember.h"
#include <string>

class SaveState { //memento
private:
    int level;
    std::string names[3];
    int hp[3];
    int dmg[3];
public:
    SaveState(int level,
              std::string n1, std::string n2, std::string n3,
              int hp1, int hp2, int hp3,
              int dmg1, int dmg2, int dmg3) {

        this->level = level;

        names[0] = n1;
        names[1] = n2;
        names[2] = n3;

        hp[0] = hp1;
        hp[1] = hp2;
        hp[2] = hp3;

        dmg[0] = dmg1;
        dmg[1] = dmg2;
        dmg[2] = dmg3;
    }

    int getLevel() { return level; }
    std::string* getNames() { return names; }
    int* getHP() { return hp; }
    int* getDmg() { return dmg; }
};

#endif
