#include <iostream>
#include "ArrayList.h"

using namespace std;

int main(){
	
	//super class, can be either of the children!
	ArrayList* asc = new AscendingArrayList(10); 
	
	asc->insertElement(10);
	asc->insertElement(20);
	asc->insertElement(15);
	asc->insertElement(25);
	asc->insertElement(5);
	
	asc->print();
	
	asc->sort();
	
	asc->print();

	delete asc;

	///////////////////


	ArrayList* desc = new DescendingArrayList(10); 

	desc->insertElement(43);
	desc->insertElement(2);
	desc->insertElement(54);
	desc->insertElement(98);
	desc->insertElement(56);

	desc->print();
	
	desc->sort();

	desc->print();

	delete desc;
	
	return 0;
}
