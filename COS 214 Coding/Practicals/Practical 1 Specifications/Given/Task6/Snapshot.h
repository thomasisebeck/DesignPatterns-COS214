#ifndef SNAPSHOT_H
#define SNAPSHOT_H
#include "AuditableSnapshot.h"

class Snapshot: public AuditableSnapshot{
private:
public:
    virtual std::string GetUsername() const;
    virtual std::string date() const;
    virtual std::string state() const;

};

#endif