#ifndef COS214_REMOTE_H
#define COS214_REMOTE_H
#include "DanceCommand.h"
#include "DieCommand.h"
#include "ReviveCommand.h"

class Remote {
private:
    DanceCommand* dance;
    DieCommand* die;
    ReviveCommand* revive;
public:
    Remote(DanceCommand* dance, DieCommand* die, ReviveCommand* revive) {
        this->dance = dance;
        this->die = die;
        this->revive = revive;
    }
    void makeDance() { dance->execute(); }
    void makeDie() { die->execute(); }
    void makeRevive() { revive->execute(); }

};

#endif
