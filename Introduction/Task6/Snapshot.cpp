#include "Snapshot.h"
#include <ctime>
#include <cstring>

Snapshot::Snapshot(std::string un, std::string pw) {
    _username = un;
    _password = pw;
    _date = this->date();
}

std::string Snapshot::GetUsername() const {
    return _username;
}

std::string Snapshot::state() const {
    return _password;
}

std::string Snapshot::date() const
{
    time_t curr;
    tm* curr_tm;
    char retTime[50];
    char retDate[50];
    char ret[100];

    time(&curr);
    curr_tm = localtime(&curr);

    strftime(retDate, 50, "%B %d, %Y", curr_tm);
    strftime(retTime, 50, "%T", curr_tm);

    strcat(ret, retDate);
    strcat(ret, ", ");
    strcat(ret, retTime);

    return ret;
}