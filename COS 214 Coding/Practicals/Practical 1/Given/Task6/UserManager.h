#ifndef USERMANAGER_H
#define USERMANAGER_H
#include "User.h"
#include "Snapshot.h"

class UserManager{
private:
    Snapshot* saves;
    int numSaves;
    User* u;
    void clearLast();
public:
    UserManager(User *User);

    void Backup();

    void Undo();

    void ShowHistory() const;
};

#endif