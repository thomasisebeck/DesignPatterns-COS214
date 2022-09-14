#include "Directory.h"
#include <iostream>

using namespace std;

Directory::Directory(string name) : Node(name, true) {}

int Directory::find(Node* item) {
    list<Node*>::iterator it;
    int i;

    for (i = 0, it = this->items.begin(); it != this->items.end(); it++, i++)
        if (*it == item)
            return i;  //index of item

    return -1; //not found
}

bool Directory::addItem(Node* item) {
    list<Node*>::iterator it;
    int index = find(item);

    if (index == -1) { //not found, can add
        this->items.push_back(item);
        return true;
    }

    //duplicate item
    return false;
}

bool Directory::removeItem(std::string name) {
    list<Node*>::iterator it;
    for (it == items.begin(); it != items.end(); it++)
        if ((*it)->getName() == name) {
            this->items.remove((*it));
            return true;
        }

    //item not found
    return false;
}

void Directory::listItems(int indent) {

    for (int i = 0; i < indent; i++)
        cout << "  ";

    string folderIcon = "▶ ";
    if (this->isDirectory())
        cout << folderIcon;

    cout << this->getName() << endl;

    list<Node*>::iterator it;
    for (it = items.begin(); it != items.end(); it++){

        if ((*it)->isDirectory()) {
            (*it)->listItems(++indent);
            indent--;
        }
        else {
            //list contents
            for (int i = 0; i < indent; i++)
                cout << "  ";
            cout << "  " << (*it)->getName() << endl;
        }
    }
}