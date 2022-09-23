#include <iostream>
#include "File.h"
#include "Directory.h"
#include "Node.h"
#include "NavigatorMemento.h"
using namespace std;

int validate(string input, int lower, int upper) {
    while (stoi(input) < lower || stoi(input) > upper){
        cout << "[Enter option between " << lower << " and " << upper << "]: ";
        getline(cin, input);
    }

    return stoi(input);
}

Directory* cmd(string command, Directory *dir, NavigatorMemento& nav) {

    if (command.find("touch ") != -1) { //make a file
        command = command.substr(command.find("touch ") + 6, command.length());

        string contents;
        cout << " Enter file contents: ";
        getline(cin, contents);
        dir->addFile(new File(command, contents));

        return dir;
    }

    if (command.find("mkdir ") != -1) { //make a directory
        command = command.substr(command.find("mkdir ") + 6, command.length());

        cout << "[1. Synchronous, 2. Asynchronous]: ";

        string sync;
        getline(cin, sync);

        int input = validate(sync, 1, 2);

        bool isSync = input == 1 ? true : false;

        dir->addDirectory(new Directory(command, isSync));

        return dir;
    }

    if (command.find("ls") != -1) { //list dir
        dir->listItems(0);
        return dir;
    }

    if (command.find("cd") != -1) {

        if (command.find("../") != -1) {
            //pop the memento off of the stack
            cout << " getting from stack... " << endl;
            dir = nav.getLastNode();
            cout << " got " << dir->getName() << endl;
            return dir;
        }

        //make dir a child of dir

        command = command.substr(command.find("cd ") + 3, command.length());
        Directory* tempDir = dir->getChildDir(command);

        if (tempDir == nullptr) {
            cout << "<< cannot find directory '" << command << "' >>" << endl;
            return dir;
        }

        //push dir onto the memento stack...
        nav.addNode(dir);
        return tempDir;
    }

    cout << "<< unrecognised command '" << command << "' >>" << endl;
}

int main() {

    //to navigate
    NavigatorMemento navigatorMemento;

    Directory* root = new Directory("root", true);
    Directory* currentFile = root;

    string currentCommand;

    currentFile = cmd("mkdir newDir", currentFile, navigatorMemento);
    currentFile = cmd("ls", currentFile, navigatorMemento);
    currentFile = cmd("cd newDir", currentFile, navigatorMemento);
    currentFile = cmd("ls", currentFile, navigatorMemento);

    while (true) {

        cout << "> ";

        getline(cin, currentCommand);

        if (currentCommand == "exit") {
            cout << "<< exiting... >>" << endl;
            return 0;
        }

        currentFile = cmd(currentCommand, currentFile, navigatorMemento);
    }



    /*root.addFile(new File("dog.docx", "story of a good dog"));

    root.addFile(new File("boy.docx", "story of a boy"));

    Directory* dir2 = new Directory("Photos", false);
    dir2->addFile(new File("lion.jpg", "a photo of a lion"));
    root.addDirectory(dir2);
    dir2->addDirectory(new Directory("Sync Directory", true));

    Directory* sf1 = new Directory("SFolder", true);
    sf1->addFile(new File("SyncProg.exe", "0011000110"));

    root.addDirectory(sf1);

    root.addFile(new File("bird.txt", "photo of a bird"));
    root.listItems(0);*/



    return 0;

}