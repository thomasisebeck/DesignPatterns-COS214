#ifndef COS214_PLAYSTYLE_H
#define COS214_PLAYSTYLE_H
#include <string>

//Strategy (interface)
class PlayStyle {
public:
    virtual std::string attack() = 0;
};

#endif
