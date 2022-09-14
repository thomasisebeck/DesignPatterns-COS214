#include <iostream>
#include "File.h"
#include "Directory.h"
#include "Node.h"
using namespace std;

int main() {

    Directory root("root", true);

    root.addItem(new File("dog.txt", "photo of a good dog"));
    root.addItem(new File("boy.txt", "photo of a boy"));

    Directory* dir2 = new Directory("Photos", false);
    dir2->addItem(new File("lion.txt", "a lion"));
    root.addItem(dir2);
    dir2->addItem(new Directory("Cannot add", true));

    Directory* sf1 = new Directory("SFolder", true);
    sf1->addItem(new File("SyncProg.exe", "0011000110"));

    root.addItem(sf1);

    root.addItem(new File("bird.txt", "photo of a bird"));
    root.listItems(0);



    return 0;

}