#include <iostream>
#include "File.h"
#include "Directory.h"
#include "Node.h"
using namespace std;

int validate(string input, int lower, int upper) {
    while (stoi(input) < lower || stoi(input) > upper){
        cout << "[Enter option between " << lower << " and " << upper << "]: ";
        getline(cin, input);
    }

    return stoi(input);
}

void cmd(string command, Directory& dir) {

    if (command.find("touch ") != -1) { //make a file
        command = command.substr(command.find("touch ") + 6, command.length());

        string contents;
        cout << " Enter file contents: ";
        getline(cin, contents);
        dir.addFile(new File(command, contents));

        return ;
    }

    if (command.find("mkdir ") != -1) { //make a directory
        command = command.substr(command.find("mkdir ") + 6, command.length());

        cout << "[1. Synchronous, 2. Asynchronous]: ";

        string sync;
        getline(cin, sync);

        int input = validate(sync, 1, 2);

        bool isSync = input == 1 ? true : false;

        dir.addDirectory(new Directory(command, isSync));

        return ;
    }

    if (command.find("ls") != -1) { //list dir
        dir.listItems(0);
        return ;
    }

    cout << "<< unrecognised command '" << command << "' >>" << endl;
}

int main() {

    Directory root("root", true);

    string currentCommand;

    while (true) {

        cout << "> ";

        getline(cin, currentCommand);

        if (currentCommand == "exit") {
            cout << "<< exiting... >>" << endl;
            return 0;
        }

        cmd(currentCommand, root);
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