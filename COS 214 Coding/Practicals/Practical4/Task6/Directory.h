#ifndef DIRECTORY_H
#define DIRECTORY_H
#include "Node.h"
#include "File.h"
#include "NodeIterator.h"
#include <list>
#include <string>
#include "ConcreteObserver.h"

class Directory : public Nlsa
        ode {
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
    void attach(ConcreteObserver* newObserver) {
        //attach myself
        virusscanner = newObserver;

        //attach my children
        std::list<Node*>::iterator it;
        for (it = items.begin(); it != items.end(); it++) {
            if ((*it)->isDirectory()) {
                dynamic_cast<Directory*>((*it))->attach(newObserver);
            }

        }

    }
    std::list<Node*>* getState() { return &items; }

};

#endif
