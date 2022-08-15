#ifndef COS214_SQUADMEMBER_H
#define COS214_SQUADMEMBER_H
#include <string>

class SquadMember {
private:
    int HP;
    int damage;
    std::string name;
public:
    SquadMember(int HP, int damage, std::string name);
    std::string getName() const;
    void setHP(int newHP);
    void setDamage(int newDamage);
    int getHP() const;
    void takeDamage(int attack);
    int getDamage() const;
    SquadMember* clone(std::string newName) const;
};


#endif
