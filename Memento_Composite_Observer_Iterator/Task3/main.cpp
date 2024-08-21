#include <iostream>
#include "File.h"
#include "Directory.h"
#include "Node.h"
#include "Navigator.h"
#include "BackupOriginator.h"
#include "BackupCaretaker.h"
#include "BackupMemento.h"
#include "Root.h"
using namespace std;

int validate(string input, int lower, int upper) {
    while (stoi(input) < lower || stoi(input) > upper){
        cout << "[Enter option between " << lower << " and " << upper << "]: ";
        getline(cin, input);
    }

    return stoi(input);
}

Directory* cmd(string command, Directory *dir, Navigator& nav, Directory* root, BackupOriginator& originator, BackupCaretaker& caretaker) {

    while (true) {

        if (command.find("delback") != -1) {
            caretaker.deleteMemento();

            cout << "<< backup deleted >>" << endl;
            return root;
        }


        if (command.find("backup") != -1) {
            //create a memento of the file system
            originator.setState(root);
            originator.storeState(caretaker);
            root->listItems(0, true);
            cout << "<< backup captured >>" << endl;
            return root;
        }

        if (command.find("restore") != -1) {
            //restore the memento of the file system

            if (caretaker.retrieveMemento() != nullptr && originator.reinstantiateMemento(caretaker.retrieveMemento())) {
                if (originator.getState() != nullptr)
                    originator.getState()->listItems(0, true);
                cout << "<< backup restored >>" << endl;
                return originator.getState();
            }

            //backup not found
            cout << "<< no backup found >>" << endl;

            return root;
        }

        if (command.find("touch ") != -1) { //make a file
            command = command.substr(command.find("touch ") + 6, command.length());

            string name = command.substr(0, command.find(" "));
            command = command.substr(command.find(" ") + 1, command.length());

            dir->addFile(new File(name, command));

            dir->listItems(0, false);

            return dir;
        }

        if (command.find("rm ") != -1) { //make a file
            command = command.substr(command.find("rm ") + 3, command.length());

            string name = command.substr(0, command.find(" "));
            command = command.substr(command.find(" ") + 1, command.length());

            if (dir->removeItem(name))
                cout << "<< removed '" << name << "' >>" << endl;
            else
                cout << "<< could not find '" << name << "' >>" << endl;

            dir->listItems(0, false);

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

    Root root;

    root.addFile(new File("Hello", "yooo"));
    root.addFile(new File("Bye", "bloop"));

    root.backup();

    cout << "State:" << endl;

    root.listItems(0, true);

    cout << "Deleting a file...." << endl;

    root.removeFile("Hello");

    cout << "State:" << endl;

    root.listItems(0, true);

    cout << "Restoring..." << endl;

  /*  root.restore();

    cout << "State:" << endl;

    root.listItems(0, true);*/


    /*BackupOriginator originator;
    BackupCaretaker caretaker;

    //to navigate
    Navigator navigatorMemento;

    Directory* root = new Directory("root", true);
    Directory* currentFile = root;

    string currentCommand;

    currentFile = cmd("mkdir photos", currentFile, navigatorMemento, root, originator, caretaker);
    currentFile = cmd("mkdir memes", currentFile, navigatorMemento, root, originator, caretaker);
    currentFile = cmd("cd photos", currentFile, navigatorMemento, root, originator, caretaker);
    currentFile = cmd("touch horse.jpg photo of horse", currentFile, navigatorMemento, root, originator, caretaker);
    currentFile = cmd("touch dog.jpg photo of dog", currentFile, navigatorMemento, root, originator, caretaker);
    currentFile = cmd("cd ../", currentFile, navigatorMemento, root, originator, caretaker);


    while (true) {

        cout << "> ";

        getline(cin, currentCommand);

        if (currentCommand == "exit") {
            cout << "<< exiting... >>" << endl;
            return 0;
        }

        if (currentCommand.find("restore") != -1) {
            root = cmd(currentCommand, currentFile, navigatorMemento, root, originator, caretaker);
            currentFile = root;
        }
        else
            currentFile = cmd(currentCommand, currentFile, navigatorMemento, root, originator, caretaker);
    }*/

}