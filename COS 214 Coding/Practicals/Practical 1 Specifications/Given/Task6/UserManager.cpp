#include "UserManager.h"
#include "User.h"
#include <iostream>
using namespace std;

UserManager::UserManager(User *User)  {

}

void UserManager::Backup() {
    std::cout << "\nUserManager: Saving User's state...\n";
    // TODO : Implement
}

void UserManager::Undo() {

}

void UserManager::ShowHistory() const {
    std::cout << "UserManager: Here's the list of historal changes:\n";
    // TODO : Implement
}
