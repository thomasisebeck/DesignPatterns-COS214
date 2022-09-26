#ifndef DIRECTORY_H
#define DIRECTORY_H
#include "Node.h"
#include <list>
#include <string>

class Directory : public Node {
private:
    std::list<Node*> items;
    bool synchronous;
public:
    friend class Observer;
	Directory(std:: string name, bool synchronous);
	bool addItem(Node* item);
	bool removeItem(std::string name);
    int find(Node* item);
	virtual void listItems(int indent);
    virtual std::string getContents();
};

#endif
