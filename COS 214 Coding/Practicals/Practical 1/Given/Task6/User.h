#ifndef USER_H
#define USER_H

#include "Snapshot.h"
#include <string>

class User {
private:
    std::string _username;
    std::string _password;
    std::string GenerateRandomString(int length = 10);
public:
    User(std::string username, std::string password);
    void SetPassword();
    void SetPassword(std::string pw);
    Snapshot Save();
    void Restore(Snapshot *memento);
};


#endif