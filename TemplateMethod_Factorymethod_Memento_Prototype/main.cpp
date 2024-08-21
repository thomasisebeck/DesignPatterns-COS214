#include <iostream>
#include <fstream>
#include "SnakeFactory.h"
#include "JaguarFactory.h"
#include "CannibalFactory.h"
#include "GorillaFactory.h"
#include "SaveRestore.h"
using namespace std;

SquadMember* s1 = nullptr;
SquadMember* s2 = nullptr;
SquadMember* s3 = nullptr;
Enemy* enemy;
SnakeFactory* snakeFact;
JaguarFactory* jaguarFact;
GorillaFactory* gorillaFact;
CannibalFactory* cannibalFact;
SaveRestore* saveGame;

void pause() {
    cout << "\nPress enter to continue...";
    cin.get();
    cin.get();
}

int validate(int min, int max, SquadMember* s1, SquadMember* s2, SquadMember* s3, int currLevel) {
    int option;
    cin >> option;

    while (option < min || option > max) {

        if (option == 0) {
            option = max + 1;
            cout << "Saving game..." << endl;
            if (s1 == nullptr || s2 == nullptr || s3 == nullptr)
                cout << "Unable to save at this time." << endl;
            else {
                fstream out;

                out.open("save.txt", ios::out);

                ofstream myfile;
                myfile.open ("checkSellExit_file_output.csv", fstream::app);
                myfile << "Hello!";
                myfile.close();

                /*
                 1
                 Lucy
                 50
                 23
                 John
                 43
                 43
                 Mary
                 43
                 23
                 */

                if (out.is_open()) {
                    out << currLevel << endl;

                    out << s1->getName() << endl;
                    out << s1->getDamage() << endl;
                    out << s1->getHP() << endl;

                    out << s2->getName() << endl;
                    out << s2->getDamage() << endl;
                    out << s2->getHP() << endl;

                    out << s3->getName() << endl;
                    out << s3->getDamage() << endl;
                    out << s3->getHP() << endl;

                    out.close();
                }
                else {
                    cout << "Can't open save file!" << endl;
                }

                cout << "Game saved." << endl;
            }
        }
        else {
            cout << "Choose an option between " << min << " and " << max << ": ";
            cin >> option;
        }

    }

    return option;
}

void displayMemberStats() {
    cout << "~~~~~~ stats ~~~~~~" << endl;
    cout << "name: " << s1->getName() << endl;
    cout << "  damage: " << s1->getDamage() << endl;
    cout << "  health: " << s1->getHP() << endl;
    cout << "name: " << s2->getName() << endl;
    cout << "  damage: " << s2->getDamage() << endl;
    cout << "  health: " << s2->getHP() << endl;
    cout << "name: " << s3->getName() << endl;
    cout << "  damage: " << s3->getDamage() << endl;
    cout << "  health: " << s3->getHP() << endl;
    cout << "~~~~~~~~~~~~~~~~~~~" << endl;
}

void restore() {
    cout << "One of your members died!" << endl;
    cout << "Restoring save..." << endl;

    int setLevel;

    string setName1;
    string setName2;
    string setName3;

    int setHP1;
    int setHP2;
    int setHP3;

    int setDmg1;
    int setDmg2;
    int setDmg3;

    saveGame->restoreGame(setLevel, setName1, setName2, setName3, setHP1, setHP2, setHP3, setDmg1, setDmg2, setDmg3);

    s1->setHP(setHP1);
    s2->setHP(setHP2);
    s2->setHP(setHP3);
}

void level2();
void level1() {
    cout << "----------- LEVEL 1 -------------" << endl;

    //always visible
    displayMemberStats();

    cout << "Your team is deep in the jungle and trying to fight their way out." << endl;
    cout << "'I'm actually getting tired of you guys,' says " << s1->getName() << endl;
    cout << "'Right back at ya,' says " << s2->getName() << endl;
    cout << "'Will you guys shut up and focus. It seems like we have company...' says " << s3->getName() << endl;

    pause();

    cout << endl << "A snake appears in the middle of the path and bears it's fangs." << endl;

    //save the game before proceeding....

    saveGame->saveGame(1, s1->getName(), s2->getName(), s3->getName(), s1->getHP(), s2->getHP(), s3->getHP(), s1->getDamage(), s2->getDamage(), s3->getDamage());

    snakeFact = new SnakeFactory;
    enemy = snakeFact->createEnemy("Whiplash", "Tail block");

    cout << "Choose a member to fight with [1: " << s1->getName() << ", 2: " << s2->getName() << ", 3: " << s3->getName() << "]" << endl;
    int memberFightSelection = validate(1, 3, s1, s2, s3, 1);

    switch(memberFightSelection) {
        case 1:
            enemy->attack(s1);
            break;
        case 2:
            enemy->attack(s2);
            break;
        case 3:
            enemy->attack(s3);
    }


    if (s1->getHP() <= 0 || s2->getHP() <= 0 || s3->getHP() < 0) {
        restore();
        level1();
    }

    cout << "Way to start the day, says " << s1->getName() << endl;

    saveGame->saveGame(1, s1->getName(), s2->getName(), s3->getName(), s1->getHP(), s2->getHP(), s3->getHP(), s1->getDamage(), s2->getDamage(), s3->getDamage());
    cout << "Game saved...\n\n";

    pause();

    displayMemberStats();

    level2();

}

void level3();
void level2() {

    cout << "----------- LEVEL 2 -------------" << endl;

    displayMemberStats();

    cout << "'I take it all back', says " << s1->getName() << ". 'You guys are the best.'" << endl;
    cout << "'Apologising won't save you from those cats,' says " << s2->getName() << "." << endl;
    cout << "'W-what cats?' asks " << s1->getName() << "." << endl;
    cout << "'The Jaguars, obviously,' says " << s3->getName() << "." << endl;
    cout << "'Oh dear,' says " << s1->getName() << "." << endl;
    cout << "'Better take this if you want to survive.' " << s2->getName() << " tosses a dagger to " << s1->getName() << "." << endl;
    cout << "----- damage for player " << s1->getName() << " increased by 5 -----" << endl;
    s1->setDamage(s1->getDamage() + 5);

    displayMemberStats();

    pause();

    cout << endl << "'Seems like it was just in time', says " << s2->getName() << "." << endl;
    cout << "'Handle this one, will you?' says " << s2->getName() << endl;

    jaguarFact = new JaguarFactory;
    enemy = jaguarFact->createEnemy("Scratch", "Paw Block");

    cout << "Choose a member to fight with [1: " << s1->getName() << ", 2: " << s2->getName() << ", 3: " << s3->getName() << "]" << endl;
    int memberFightSelection = validate(1, 3, s1, s2, s3, 1);

    saveGame->saveGame(2, s1->getName(), s2->getName(), s3->getName(), s1->getHP(), s2->getHP(), s3->getHP(), s1->getDamage(), s2->getDamage(), s3->getDamage());

    bool flag1 = false;
    bool flag2 = false;
    bool flag3 = false;

    switch(memberFightSelection) {
        case 1:
            enemy->attack(s1);
            flag1 = true;
            break;
        case 2:
            enemy->attack(s2);
            flag2 = true;
            break;
        case 3:
            enemy->attack(s3);
            flag3 = true;
    }

    if (s1->getHP() <= 0 || s2->getHP() <= 0 || s3->getHP() < 0) {
        restore();
        level2();
    }

    saveGame->saveGame(2, s1->getName(), s2->getName(), s3->getName(), s1->getHP(), s2->getHP(), s3->getHP(), s1->getDamage(), s2->getDamage(), s3->getDamage());
    cout << "Game saved...\n\n";

    displayMemberStats();

    pause();

    cout << "\n\n'Uuurgh,' says ";

    if (flag1) cout << s1->getName();
    if (flag2) cout << s2->getName();
    if (flag3) cout << s3->getName();

    bool oneSpoke = false;
    bool twoSpoke = false;
    bool threeSpoke = false;

    cout << ". 'Time for you guys to start pulling your weight too.'" << endl;
    if (!flag1) {
        cout << "'Well, I'm the only girl here,' says " << s1->getName() << "." << endl;
        oneSpoke = true;
    }
    else if (!flag2) {
        cout << "'Well, I'm the only girl here,' says " << s2->getName() << "." << endl;
        twoSpoke = true;
    }

    if (!flag3) {
        cout << "'That's not a vary girly name, you have there ,' says " << s3->getName() << "." << endl;
        threeSpoke = true;
    }
    else if (!flag2) {
        cout << "'That's not a vary girly name, you have there ,' says " << s2->getName() << "." << endl;
        twoSpoke = true;
    }

    cout << "'Will you stop bickering, we made it through!', says ";

    if (!oneSpoke)
        cout << s1->getName() << "." <<  endl;
    if (!twoSpoke)
        cout << s2->getName() << "." <<  endl;
    if (!threeSpoke)
        cout << s3->getName() << "." <<  endl;

    cout << endl;

    displayMemberStats();

    saveGame->saveGame(2, s1->getName(), s2->getName(), s3->getName(), s1->getHP(), s2->getHP(), s3->getHP(), s1->getDamage(), s2->getDamage(), s3->getDamage());
    cout << "Game saved...\n\n";

    level3();

}

void level4();
void level3() {
    cout << "----------- LEVEL 3 -------------" << endl;

    displayMemberStats();

    cout << "'I just want to get off of this damned island,' says " << s1->getName() << "." << endl;
    cout << "'We ain't going till we've gotten rid of all the Caniibals!' says " << s2->getName() << "." << endl;
    cout << "'I suppose someone needs to take care of them.' says " << s1->getName() << "." << endl;
    cout << "'Watch out, there's a big monkey up ahead!' yells " << s3->getName() << "." << endl;

    cout << "Choose a member to fight with [1: " << s1->getName() << ", 2: " << s2->getName() << ", 3: " << s3->getName() << "]" << endl;
    int memberFightSelection = validate(1, 3, s1, s2, s3, 1);

    saveGame->saveGame(3, s1->getName(), s2->getName(), s3->getName(), s1->getHP(), s2->getHP(), s3->getHP(), s1->getDamage(), s2->getDamage(), s3->getDamage());

    gorillaFact = new GorillaFactory;
    enemy = gorillaFact->createEnemy("Chest thump", "Oof oof");

    switch(memberFightSelection) {
        case 1:
            enemy->attack(s1);
            break;
        case 2:
            enemy->attack(s2);
            break;
        case 3:
            enemy->attack(s3);
    }

    if (s1->getHP() <= 0 || s2->getHP() <= 0 || s3->getHP() < 0) {
        restore();
        level3();
    }

    displayMemberStats();

    saveGame->saveGame(3, s1->getName(), s2->getName(), s3->getName(), s1->getHP(), s2->getHP(), s3->getHP(), s1->getDamage(), s2->getDamage(), s3->getDamage());
    cout << "Game saved...\n\n";

    pause();

    cout << "'I'm beginning to wonder whether we're going to make it out of here,' says " << s2->getName() << "." << endl;
    cout << "'You've always been the pessimistic one,' says " << s3->getName() << "." << endl;
    cout << "'Well, every hour I stay alive is a victory in my opinion,' says " << s1->getName() << "." << endl;

    pause();

    level4();

}

void level4() {
    cout << "----------- LEVEL 4 -------------" << endl;

    displayMemberStats();

    cout << "A golden orb falls down from the sky, one of you players gets a massive health an damage boost!" << endl;
    cout << "Choose a member to give it to [1: " << s1->getName() << ", 2: " << s2->getName() << ", 3: " << s3->getName() << "]" << endl;
    int healthBoost = validate(1, 3, s1, s2, s3, 4);

    switch(healthBoost) {
        case 1:
            s1->setHP(50);
            s1->setDamage(15);
            break;
        case 2:
            s2->setHP(50);
            s2->setDamage(15);
            break;
        case 3:
            s3->setHP(50);
            s3->setDamage(15);
    }

    cout << "Your stats just increased!" << endl;

    displayMemberStats();

    pause();

    cout << "'I've had enough of this!,' says " << s1->getName() << "." << endl;
    cout << "'Always the first to complain,' mutters " << s2->getName() << "." << endl;
    cout << "'I hope you two are strong enough to fight the cannibals, ' says " << s3->getName() << "." << endl;

    if (s1->getHP() < s2->getHP() && s1->getHP() < s3->getHP())
        cout << "'Certainly won't be me, I barely have any strength left,' says " << s1->getName() << "." << endl;
    if (s2->getHP() < s1->getHP() && s2->getHP() < s3->getHP())
        cout << "'Certainly won't be me, I barely have any strength left,' says " << s2->getName() << "." << endl;
    if (s3->getHP() < s1->getHP() && s3->getHP() < s2->getHP())
        cout << "'Certainly won't be me, I barely have any strength left,' says " << s3->getName() << "." << endl;

    cout << "'We'll have to choose wisely next time,' says " << s1->getName() << "." << endl;

    pause();

    cout << "'Too late to ponder over it now! We seem to have met out match!' yells " << s2->getName() << "." << endl;
    cout << "'That's the biggest Cannible I've seen yet,' says " << s1->getName() << "." << endl;

    cout << "Choose a member to fight with [1: " << s1->getName() << ", 2: " << s2->getName() << ", 3: " << s3->getName() << "]" << endl;
    int memberFightSelection = validate(1, 3, s1, s2, s3, 4);

    saveGame->saveGame(4, s1->getName(), s2->getName(), s3->getName(), s1->getHP(), s2->getHP(), s3->getHP(), s1->getDamage(), s2->getDamage(), s3->getDamage());

    cannibalFact = new CannibalFactory;
    enemy = cannibalFact->createEnemy("Flesh Eater", "Body Block");

    switch(memberFightSelection) {
        case 1:
            enemy->attack(s1);
            break;
        case 2:
            enemy->attack(s2);
            break;
        case 3:
            enemy->attack(s3);
    }

    if (s1->getHP() <= 0 || s2->getHP() <= 0 || s3->getHP() < 0) {
        restore();
        level4();
    }

    displayMemberStats();

    pause();

    cout << "---------------------------------" << endl;
    cout << "--------- GAME FINISHED! --------" << endl;
    cout << "---------------------------------" << endl;

}

int main() {

    //NB: put save.txt in cmake-build-debug!!!!


    //new Game default
    int currLevel = 1;

    cout << "1. Restore saved game." << endl;
    cout << "2. newGame." << endl;
    int restoreOrNew = validate(1, 2, s1, s2, s3, currLevel);

    saveGame = new SaveRestore;

    if (restoreOrNew == 1) {
        /*
         1
         Lucy
         50
         23
         John
         43
         43
         Mary
         43
         23
         */

        string name;
        int HP;
        int damage;

        ifstream file("save.txt");
        file >> currLevel;

        /////////////// s1 //////////////

        file >> name;
        file >> HP;
        file >> damage;

        s1 = new SquadMember(HP, damage, name);

        /////////////// s2 //////////////

        file >> name;
        file >> HP;
        file >> damage;

        s2 = new SquadMember(HP, damage, name);

        /////////////// s3 //////////////

        file >> name;
        file >> HP;
        file >> damage;

        s3 = new SquadMember(HP, damage, name);

        cout << "Restored saved game." << endl;

        switch (currLevel) {
            case 1: level1();
                break;
            case 2: level2();
                break;
            case 3: level3();
        }

    }
    else { //New game

        cout << "Welcome to adventure island!!!" << endl;
        cout << "Time to create your squad members." << endl;

        string name1, name2, name3;

        cout << "Name your first squad member: " << endl;
        cin >> name1;
        cout << "Name your second squad member: " << endl;
        cin >> name2;
        cout << "Name your third squad member: " << endl;
        cin >> name3;

        int dmg = rand() % 3 + 3; //from 3 to 6
        int HP = rand() % 20 + 20;  //from 20 to 40
        s1 = new SquadMember(HP, dmg, name1);

        dmg = rand() % 3 + 3; //from 3 to 6
        HP = rand() % 20 + 20;  //from 20 to 40
        s2 = new SquadMember(HP, dmg, name2);

        dmg = rand() % 3 + 3; //from 3 to 6
        HP = rand() % 20 + 20;  //from 20 to 40
        s3 = new SquadMember(HP, dmg, name3);

        cout << "Here is your team: " << endl;
        cout << "Member 1: " << endl;
        cout << "Name: " << s1->getName() << endl;
        cout << "HP: " << s1->getHP() << endl;
        cout << "Damage: " << s1->getDamage() << endl;
        cout << "Member 2: " << endl;
        cout << "Name: " << s2->getName() << endl;
        cout << "HP: " << s2->getHP() << endl;
        cout << "Damage: " << s2->getDamage() << endl;
        cout << "Member 3: " << endl;
        cout << "Name: " << s3->getName() << endl;
        cout << "HP: " << s3->getHP() << endl;
        cout << "Damage: " << s3->getDamage() << endl;

        level1();

    }


    return 0;

}


