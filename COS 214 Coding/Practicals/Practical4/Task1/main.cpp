#include <iostream>
#include "File.h"
#include "Directory.h"
#include "Node.h"
using namespace std;

int main() {

    Directory root("root");

    root.addItem(new File("dog.jpg", "photo of a good dog"));
    root.addItem(new File("boy.jpg", "photo of a boy"));

    Directory* dir2 = new Directory("Photos");

    dir2->addItem(new File("lion.jpg", "a lion"));

    root.addItem(dir2);

    root.addItem(new File("bird.jpg", "photo of a bird"));

    root.listItems(0);


    return 0;

}