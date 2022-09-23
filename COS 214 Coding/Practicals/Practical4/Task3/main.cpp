#include <iostream>
#include "File.h"
#include "Directory.h"
#include "Node.h"
using namespace std;

int main() {

    Directory root("root", true);

    root.addFile(new File("dog.docx", "story of a good dog"));

    root.addFile(new File("boy.docx", "story of a boy"));

    Directory* dir2 = new Directory("Photos", false);
    dir2->addFile(new File("lion.jpg", "a photo of a lion"));
    root.addDirectory(dir2);
    dir2->addDirectory(new Directory("Sync Directory", true));

    Directory* sf1 = new Directory("SFolder", true);
    sf1->addFile(new File("SyncProg.exe", "0011000110"));

    root.addDirectory(sf1);

    root.addFile(new File("bird.txt", "photo of a bird"));
    root.listItems(0);





    return 0;

}