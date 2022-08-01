#ifndef USERMANAGER_H
#define USERMANAGER_H
#include "User.h"

class UserManager{
public:
    UserManager(User *User);

    void Backup();

    void Undo();

    void ShowHistory() const;
};

#endif