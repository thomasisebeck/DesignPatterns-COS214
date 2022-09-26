#ifndef DIRECTORY_H
#define DIRECTORY_H
#include "Node.h"
#include "File.h"
#include "NodeIterator.h"
#include <list>
#include <string>
#include "ConcreteObserver.h"

class Directory : public Node {
    friend class ConcreteObserver;
private:
    std::list<Node*> items;
    bool synchronous;
    ConcreteObserver* virusscanner;
public:
	Directory(std:: string name, bool synchronous);
    Directory(Directory& old);
    virtual ~Directory();
    void addDirectory(Directory * dir);
    void removeDirectory(std::string name);
    bool listDirectories();
    bool isEmpty();
    void addFile(File* f);
    void removeFile(std::string name);
    bool listFiles(); //calls list items
    Directory* getChildDir(std::string name);

    virtual void listItems(int indent, bool listAll);

	bool removeItem(std::string name);
    int find(Node* item);
    int getIndex(std::string name);
    virtual std::string getContents();
    virtual bool isSynchronous() { return synchronous; }
    void attach(ConcreteObserver* newObserver) { virusscanner = newObserver; }

};

#endif
