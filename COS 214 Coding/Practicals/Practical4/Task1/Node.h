#ifndef NODE_H
#define NODE_H
#include <string>

class Node {
private:
	std::string name;
	bool directory;
public:
    Node(std::string name, bool directory) {
        this->name = name;
        this->directory = directory;
    }
    std::string getName() { return name; }
	bool rename(std::string newName) {
        this-> name = newName;
        return true;
    }
    bool isDirectory() { return this->directory; }
    virtual void listItems(int indent) = 0;
};

#endif
