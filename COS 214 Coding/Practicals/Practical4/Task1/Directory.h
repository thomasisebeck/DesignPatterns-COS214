#ifndef DIRECTORY_H
#define DIRECTORY_H
#include "Node.h"
#include <list>
#include <string>

class Directory : public Node {
private:
    std::list<Node*> items;
public:
	Directory(std:: string name);
	bool addItem(Node* item);
	bool removeItem(std::string name);
    int find(Node* item);
	virtual void listItems(int indent);
};

#endif
