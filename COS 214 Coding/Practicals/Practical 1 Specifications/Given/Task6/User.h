#ifndef USER_H
#define USER_H

#include "AuditableSnapshot.h"
#include <string>

class User {
private:
    std::string _username;
    std::string _password;
    std::string GenerateRandomString(int length = 10);
public:
    User(std::string username, std::string password);
    void SetPassword();
    AuditableSnapshot* Save();
    void Restore(AuditableSnapshot *memento);
};


#endif