#ifndef COS214_SAVERESTORE_H
#define COS214_SAVERESTORE_H
#include "StateCare.h"
#include "SaveState.h"
#include <iostream>

class SaveRestore { //originator
private:
    SaveState* save;
    StateCare* care;
public:
    SaveRestore() {
        care = new StateCare();
    };
    void saveGame(int level,
                  std::string n1, std::string n2, std::string n3,
                  int hp1, int hp2, int hp3,
                  int dmg1, int dmg2, int dmg3) {
        //create state object

        save = new SaveState(level, n1, n2, n3, hp1, hp2, hp3, dmg1, dmg2, dmg3);
        care->setMemento(save);
    }

    void restoreGame(int& level,
                     std::string& n1, std::string& n2, std::string& n3,
                     int& hp1, int& hp2, int& hp3,
                     int& dmg1, int& dmg2, int& dmg3) {
        save = care->getMemento();

        level = save->getLevel();

        std::string* names = save->getNames();
        n1 = names[0];
        n2 = names[1];
        n2 = names[2];

        int* hps = save->getHP();
        hp1 = hps[0];
        hp2 = hps[1];
        hp3 = hps[2];

        int* dmgs = save->getDmg();
        dmg1 = dmgs[0];
        dmg2 = dmgs[1];
        dmg3 = dmgs[2];

        std::cout << "Game restored..." << std::endl;
    }
};

#endif
