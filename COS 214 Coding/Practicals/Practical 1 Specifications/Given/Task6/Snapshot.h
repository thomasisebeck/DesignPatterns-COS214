#ifndef SNAPSHOT_H
#define SNAPSHOT_H
#include "AuditableSnapshot.h"

//Uses interface of AuditableSnapshot

//State
class Snapshot: public AuditableSnapshot{
private:
    std::string _username;
    std::string _password;
    std::string _date;
public:
    Snapshot(){};
    Snapshot(std::string un, std::string pw);
    virtual std::string GetUsername() const;
    virtual std::string date() const;
    virtual std::string state() const;

};

#endif