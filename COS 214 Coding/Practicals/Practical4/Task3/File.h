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
    virtual void listItems(int indent){}; //Do nothing
    virtual bool listFiles() { return false; }
};

#endif
