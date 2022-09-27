#include "Directory.h"
#include <iostream>
#include <cstdio>
#include "Windows.h"

using namespace std;

Directory::Directory(string name, bool synchronous) : Node(name, true) {
    this->synchronous = synchronous;
    this->virusscanner = nullptr;
}

//copy constructor
Directory::Directory(Directory &old) : Node(old.getName(), true) {
    std::list<Node*>::iterator it;

    for (it = this->items.begin(); it != this->items.end(); it++)
        delete (*it);

    for (it = old.items.begin(); it != old.items.end(); it++) {
        if ((*it)->isDirectory())
            this->items.push_back(new Directory(*dynamic_cast<Directory*>(*it)));
        else
            this->items.push_back(new File(*dynamic_cast<File*>(*it)));
    }

    this->synchronous = old.synchronous;
}

Directory::~Directory() {
    //delete the files...
    std::list<Node*>::iterator iter;
    for (iter = items.begin(); iter != items.end(); iter++)
        delete (*iter);

    delete virusscanner;
}

// --------------- UTILITIES --------------//

Directory* Directory::getChildDir(std::string name) {
    NodeIterator iter(this->items);

    int i = 0;
    while (iter.hasNext()) {
        if (iter.current()->getName() == name && iter.current()->isDirectory())
            return dynamic_cast<Directory *>(iter.current());
        i++;
        ++iter;
    }

    return nullptr; //not found
}

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

    //Notify the observer
    if (virusscanner != nullptr)
        virusscanner->update(&this->items);

}

bool Directory::removeItem(string name) {

    NodeIterator iter(this->items);

    while (iter.hasNext()) {
        if (iter.current()->getName() == name) {
            this->items.remove((iter.current()));
            return true;
        }
        ++iter;
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

void Directory::listItems(int indent, bool listAll) {

    SetConsoleOutputCP(CP_UTF8);
    setvbuf(stdout, nullptr, _IOFBF, 1000);


    for (int i = 0; i < indent; i++)
        cout << "  ";

    if (this->isDirectory())
        cout << "⬒ ";

    cout << this->getName() << (this->synchronous ? " § " : "") << endl;

    list<Node*>::iterator it;
    for (it = items.begin(); it != items.end(); it++){

        if ((*it)->isDirectory()) {
            if (listAll) {
                (*it)->listItems(++indent, true);
                indent--;
            }
            else {
                cout << "  ⬒ " << (*it)->getName() << ((*it)->isSynchronous() ? " § " : "") << endl;
            }
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