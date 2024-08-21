#ifndef FILE_H
#define FILE_H
#include <string>
#include "Node.h"

class File : public Node {
private:
    std::string contents;
public:
    File(std::string name, std::string contents) : Node(name, false) {
        this->contents = contents;
    }
    std::string getContents() { return contents; }
	void updateContents(std::string newContents) { this->contents = newContents; }
    virtual void listItems(int indent, bool listAll){}; //Do nothing
    virtual bool listFiles() { return false; }
    virtual bool isSynchronous() { return false; }
};

#endif
