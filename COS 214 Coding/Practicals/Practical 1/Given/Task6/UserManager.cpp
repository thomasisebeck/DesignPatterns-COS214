#include "UserManager.h"
#include "User.h"
#include <iostream>
using namespace std;

UserManager::UserManager(User *User)  {
  saves = new Snapshot[5];

  numSaves = 0;
  u = User;
}

void UserManager::clearLast() {
    //deleting the last entry

    for (int i = 0; i < 4; i++)
        saves[i] = saves[i + i];
}

void UserManager::Backup() {
    std::cout << endl << "UserManager: Saving User's state..." << endl;
    // TODO : Implement

    if (numSaves < 5) {
        saves[numSaves++] = u->Save();
        return ;
    }

    clearLast();
    numSaves--;
    saves[numSaves++] = u->Save();


}

void UserManager::Undo() {
    //Get password of last save
    if (numSaves > 0)
        u->Restore(&saves[--numSaves]);
    else
        std::cout << "No saves found!" << endl;
}

void UserManager::ShowHistory() const {
    std::cout << "UserManager: Here's the list of historal changes:" << endl;
    for (int i = 0; i < 5; i++) {
        if (&saves[i] != nullptr && saves[i].state() != "")
            cout << saves[i].state() << endl;
    }
}
