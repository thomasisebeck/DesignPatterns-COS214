#include "User.h"
#include "Snapshot.h"
#include <iostream>
#include <string>
using namespace std;

string User::GenerateRandomString(int length) {
    const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    int stringLength = sizeof(alphanum) - 1;

    std::string random_string;
    for (int i = 0; i < length; i++) {
      random_string += alphanum[std::rand() % stringLength];
    }
    return random_string;
}


User::User(string username, string password)
                            : _username(username), _password(password){
    cout << "User: I have been initialized with username "
         << this->_username << " and a password of " << this->_password << "\n";
}

void User::SetPassword(std::string pw) {
    this->_password = pw;
}

void User::SetPassword() {
    cout << "User: Setting a new secure password.\n";

    // TODO : Implement
    this->_password = GenerateRandomString();
    cout << "User: My password has been changed to: " << this->_password << "\n";
}

Snapshot User::Save() {
    // TODO : Implement
    Snapshot a(this->_username, this->_password);
    return a;
}

void User::Restore(Snapshot *memento) {
    this->_password = memento->state();
    cout << "User: My password has changed to: " << this->_password << "\n";
}

