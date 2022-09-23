#include "Directory.h"
#include <iostream>
#include <Windows.h>
#include <cstdio>

using namespace std;

Directory::Directory(string name, bool synchronous) : Node(name, true) {
    this->synchronous = synchronous;
}

// --------------- UTILITIES --------------//

int Directory::find(Node* item) {

    NodeIterator iter(this->items);

    int i = 0;
    while (iter.hasNext()) {
        if (iter.current() == item)
            return i;
        i++;
        ++iter;
    }

    return -1; //not found
}

// --------- ADDING & REMOVING  -----------//

void Directory::addDirectory(Directory * dir) {

    if (find(dir) != -1) { //duplicate
        cout << "<<error: cannot add duplicate directory>>" << endl;
        return;
    }

    if (!this->synchronous) { //is async && directory
        //cheeck that the dicretory is not syncrhonous
        if (dir->synchronous) { //item is async
            cout << "<<error: cannot add synchronous directory '" << dir->getName() << "' in an async directory '"
                 << this->getName() << "'>>" << endl;
            return;
        }
    }

    //not duplicate, add
    this->items.push_back(dir);

}

void Directory::addFile(File* file) {
    if (find(file) != -1) { //duplicate
        cout << "<<error: cannot add duplicate file>>" << endl;
        return;
    }

    //not duplicate
    this->items.push_back(file);
}

bool Directory::removeItem(string name) {

    NodeIterator iter(this->items);
    while (iter.hasNext())
        if (iter.current()->getName() == name) {
            this->items.remove((iter.current()));
            return true;
        }

    //item not found
    return false;
}

void Directory::removeDirectory(std::string name) {
    this->removeItem(name);
}

void Directory::removeFile(std::string name) {
    this->removeItem(name);
}

// ---------- GETTING CONTENTS ------------//

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

bool Directory::listFiles() {
    //go through list and check for a file
    auto it = items.begin();

    while (it != items.end()) {
        if (!(*it)->isDirectory()) //contains a file
            return true;
        it++;
    }
    return false;
}

bool Directory::listDirectories() {
    //go through list and check for a directory
    auto it = items.begin();

    while (it != items.end()) {
        if ((*it)->isDirectory()) //contains a file
            return true;
        it++;
    }
    return false;
}