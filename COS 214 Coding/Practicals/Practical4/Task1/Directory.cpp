#include "Directory.h"
#include <iostream>
#include <Windows.h>
#include <cstdio>

using namespace std;

Directory::Directory(string name, bool synchronous) : Node(name, true) {
    this->synchronous = synchronous;
}

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

    if (!this->synchronous && item->isDirectory()) { //is async && directory
        //cheeck that the dicretory is not syncrhonous
        if (dynamic_cast<Directory*>(item)->synchronous) { //item is async
            cout << "<<error: cannot add synchronous '" << item->getName() << "' in an async folder '" << this->getName() << "'>>" << endl;
            return false;
        }
    }

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

std::string Directory::getContents(){
    return ""; //empty
}

void Directory::listItems(int indent) {

    for (int i = 0; i < indent; i++)
        cout << "  ";

    // Set console code page to UTF-8 so console known how to interpret string data
    SetConsoleOutputCP(CP_UTF8);

    // Enable buffering to prevent VS from chopping up UTF-8 byte sequences
    setvbuf(stdout, nullptr, _IOFBF, 1000);


    string folderIcon = "⬒ ";

    if (this->isDirectory())
        cout << folderIcon;

    cout << this->getName() << (this->synchronous ? " § " : "") << endl;

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
            cout << "  ☐ " << (*it)->getName() << " [" << (*it)->getContents() << "]" << endl;

        }
    }
}