#ifndef COS214_POKEMON_H
#define COS214_POKEMON_H
#include <string>
#include "BattleState.h"
#include "PlayStyle.h"

class Pokemon {
private:
    std::string name;
    int HP;
    int damage;
    BattleState* state;
    PlayStyle* strategy;
public:
    Pokemon(std::string name, int HP, int damage, PlayStyle* initialPlaystyle) {
        this->name = name;
        this->HP = HP;
        this->damage = damage;

        //Poke always starts with a normal battle state
        this->state = new NormalBattleState;

        //set the initial play style externally
        this->strategy = initialPlaystyle;
    }
    std::string getName() { return name; }
    int getHP() { return HP; }
    int getDamage() { return damage; }
    void setHP(int newHP) { HP = newHP; }

    void selectBattleState(BattleState* state) {
        delete this->state;
        this->state = state;
        state->handle(name, damage);
    }

    void takeDamage(int dmg) { this->HP -= dmg; }

    void attack(Pokemon& enemy) {
        cout << this->getName() << " is attacking the opposing Pokemon." << endl;
        enemy.takeDamage(this->getDamage());
        if (enemy.HP <= 0)
            cout << enemy.getName() << " has fainted and can not attack." << endl;
        else {
            cout << "[" << this->getName() << " HP: " << this->getHP() << "]" << endl;
            cout << "<" << enemy.getName() << " HP: " << enemy.getHP() << ">" << endl;
            enemy.attack(*this);
        }
    }

    void selectPlayStyle(PlayStyle* newPlayStyle) {
        delete this->strategy;
        this->strategy = newPlayStyle;
    }
};

#endif