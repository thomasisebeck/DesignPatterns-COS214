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

    while (true) {

        if (command.find("touch ") != -1) { //make a file
            command = command.substr(command.find("touch ") + 6, command.length());

            string name = command.substr(0, command.find(" "));
            command = command.substr(command.find(" ") + 1, command.length());

            dir->addFile(new File(name, command));

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

            dir->listItems(0, false);

            return dir;
        }

        if (command.find("lsa") != -1) { //list all directories
            dir->listItems(0, true);
            return dir;
        }

        if (command.find("ls") != -1) { //list current directories
            dir->listItems(0, false);
            return dir;
        }

        if (command.find("cd") != -1) {

            if (command.find("../") != -1) {
                if (dir->getName() == "root") {
                    dir->listItems(0, false);
                    return dir; //can't go up from root
                }

                //pop the memento off of the stack
                dir = nav.getLastNode();
                dir->listItems(0, false);
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
            tempDir->listItems(0, false);
            return tempDir;
        }

        cout << "<< unrecognised command '" << command << "' >>" << endl;

        cout << ">";

        getline(cin, command);
    }
}

int main() {

    //TODO: create a snapshot file system (backup memento for root node)

    //to navigate
    NavigatorMemento navigatorMemento;

    Directory* root = new Directory("root", true);
    Directory* currentFile = root;

    string currentCommand;

    currentFile = cmd("mkdir photos", currentFile, navigatorMemento);
    currentFile = cmd("mkdir memes", currentFile, navigatorMemento);
    currentFile = cmd("cd photos", currentFile, navigatorMemento);
    currentFile = cmd("touch horse.jpg photo of horse", currentFile, navigatorMemento);
    currentFile = cmd("touch dog.jpg photo of dog", currentFile, navigatorMemento);
    currentFile = cmd("cd ../", currentFile, navigatorMemento);


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