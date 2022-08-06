#include <iostream>
#include "Overloading.h"
using namespace std;

int main() {

	Overloading o("Child Henry");

	o.addWheel();

	cout << o.getNumWheels() << endl;

	o.addWheel(2); 

	cout << o.getNumWheels() << endl;

	cout << o.getName() << endl;

	return 0;
}