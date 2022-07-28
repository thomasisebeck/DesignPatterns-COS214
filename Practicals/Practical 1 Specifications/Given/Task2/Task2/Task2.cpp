#include <iostream>
using namespace std;

//abstract
class ClassA {
	public:  
		ClassA() { cout << "ClassA's Empty Constructor is Called" << endl; }
		virtual ~ClassA() { cout << "ClassA's Destructor is Called" << endl; }
		virtual void print() = 0; 
};

class ClassB {
	public: 
		ClassB() { "ClassB's Empty Constructor is Called"; }
		~ClassB() { cout << "ClassB's Destructor is Called" << endl; }
		void print() { cout << "I am B!" << endl; }
};

class ClassC : public ClassA {
	public:
		ClassC():ClassA() { cout << "ClassC's Empty Constructor is Called" << endl; }
		virtual ~ClassC() { cout << "ClassC's Destructor is Called" << endl; }
		virtual void print() { cout << "I am C!" << endl; }
};

class ClassD : public ClassA, public ClassB {
	public: 
		ClassD():ClassA(), ClassB() { "ClassD's Empty Constructor is Called"; }
		virtual ~ClassD() { cout << "ClassD's Destructor is Called" << endl; }
		virtual void print() { cout << "I am D!" << endl; }
};

class ClassE : public ClassD {
	public: 
		ClassE():ClassD() { "ClassE's Empty Constructor is Called"; }
		virtual ~ClassE() { cout << "ClassE's Destructor is Called" << endl; }
		virtual void print() {  cout << "I am E!" << endl; }
};


int main()
{
	ClassC c; 
	c.print();
	
	return 0;
}

