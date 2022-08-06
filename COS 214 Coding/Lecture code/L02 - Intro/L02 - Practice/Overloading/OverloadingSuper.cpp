#include "OverloadingSuper.h"
#include <iostream>
#include <string>
using namespace std;

/*
class OverloadingSuper {
private:

public:
	OverloadingSuper();
	virtual void print();
};*/

OverloadingSuper::OverloadingSuper() {
	cout << "Creating a super class" << endl;
	this->name = "Default name";
}

OverloadingSuper::OverloadingSuper(string n) {
	cout << "Creating a super class" << endl;
	this->name = n;
}

void OverloadingSuper::print() {
	cout << "I am a super class" << endl;
}

OverloadingSuper::~OverloadingSuper() {
	cout << "Deleting the super class" << endl;
}


string OverloadingSuper::getName() { return this->name; }
