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
    virtual ~Node()= default;
    std::string getName() { return name; }
	bool rename(std::string newName) {
        this-> name = newName;
        return true;
    }
    virtual bool isSynchronous() = 0;
    bool isDirectory() { return this->directory; }
    virtual void listItems(int indent, bool listAll) = 0;
    virtual bool listFiles() = 0;
    virtual std::string getContents() = 0;
};

#endif
