#include "Overloading.h"
#include <iostream>
using namespace std;

/*
class Overloading {
private:
	int numWheels;
	std::string name;
public:
	Overloading();
	void addWheel(int);
	void addWheel();
	~Overloading();
	std::string getName();
	int getNumWheels();
	virtual ~Overloading();

};*/

Overloading::Overloading() { 
	cout << "created a sub class" << endl; 
	this->numWheels = 0;
}

Overloading::Overloading(string n):OverloadingSuper(n) {
	cout << "created a sub class and initialised name" << endl;
	this->numWheels = 0;
}

void Overloading::addWheel(int num) { this->numWheels += num; }

void Overloading::addWheel() { this->numWheels++; }

Overloading::~Overloading() { cout << "deleted the sub class" << endl;  }

int Overloading::getNumWheels() { return this->numWheels; }