#include <iostream>
#include "File.h"
#include "Directory.h"
#include "Node.h"
using namespace std;

void command(string cmd, Directory& addTo) {
    if (cmd.find("touch ") != -1) { //create a file

        string contents;

        cmd = cmd.substr(cmd.find("touch ") + 6, cmd.length());

        cout << "enter file contents: " << endl;
        getline(cin, contents);

        addTo.addItem(new File(cmd, contents));

        cout << "<< created file: '" << cmd << "' >>" << endl;

        return ;
    }

    if (cmd.find("ls") != -1) { //list directories
        addTo.listItems(0);

        return ;
    }

    if (cmd.find(" "))
        cout << "<< unrecognised command '" << cmd << "' >>" << endl;
    else
        cout << "<< invalid command >> " << endl;
}

int main() {

    Directory root("root");

    string cmd;

    while (true) {

        cout << "enter command: " << endl;

        getline(cin, cmd);

        if (cmd.find("exit") == 0) { //first pos
            cout << "<< exiting.... >>";
            exit(0);
        }

        command(cmd, root);

    }




   /* root.addItem(new File("dog.jpg", "photo of a good dog"));
    root.addItem(new File("boy.jpg", "photo of a boy"));

    Directory* dir2 = new Directory("Photos");

    dir2->addItem(new File("lion.jpg", "a lion"));

    root.addItem(dir2);

    root.addItem(new File("bird.jpg", "photo of a bird"));

    root.listItems(0);*/


    return 0;

}