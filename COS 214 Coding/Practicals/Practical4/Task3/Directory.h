#ifndef DIRECTORY_H
#define DIRECTORY_H
#include "Node.h"
#include "File.h"
#include "NodeIterator.h"
#include <list>
#include <string>

class Directory : public Node {
private:
    std::list<Node*> items;
    bool synchronous;
public:
	Directory(std:: string name, bool synchronous);
    void addDirectory(Directory * dir);
    void removeDirectory(std::string name);
    bool listDirectories();
    bool isEmpty();
    void addFile(File* f);
    void removeFile(std::string name);
    bool listFiles(); //calls list items

    virtual void listItems(int indent);

	bool addItem(Node* item);
	bool removeItem(std::string name);
    int find(Node* item);
    virtual std::string getContents();

};

#endif
