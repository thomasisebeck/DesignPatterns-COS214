#include <iostream>
using namespace std;
#include "ArrayList.h"

ArrayList::ArrayList(){
	size = 50;
	storage = new int[size];
	current = -1;
}

ArrayList::ArrayList(int s) {
	size = s;
	storage = new int[size];
	current = -1;
}

bool ArrayList::insertElement(int element) {
	if (!isFull()) {
		current++;
		storage[current] = element;
		return true;
	}
	return false;
}

void ArrayList::sort(){
	for (int i = current; i > 0; --i) {
		for (int j = 1; j <= i ; ++j) {

			//use the direction operator of the sub class to sort, returns false or true if asc or desc 
			if (directionOperator(storage[j-1],storage[j])) {
				int temp = storage[j-1];
				storage[j-1] = storage[j];
				storage[j] = temp;
			}
		}
	}
}

bool ArrayList::isFull(){
	return current >= size;
}

bool ArrayList::isEmpty(){
	return current == -1;
}

void ArrayList::print(){
	for (int i = 0; i <= current; i++) {
		std::cout << storage[i] <<  " ";
	}
	std::cout  << std::endl;
}

ArrayList::~ArrayList() {
	delete [] storage;
}


bool ArrayList::directionOperator(int, int) {
	//overloaded in each subclass to return false/true depeding on asc or desc
	std::cout << "Please implement this function in the subclasses" << std::endl;
	return true;
}


AscendingArrayList::AscendingArrayList() : ArrayList() {
	cout << "Empyt asc array list created" << endl;
}

AscendingArrayList::AscendingArrayList(int size) : ArrayList(size) {
	cout << "Asc array list of size " << size << " created" << endl;
}

string AscendingArrayList::getName() {
	return "Ascending array List"; 
}

bool AscendingArrayList::directionOperator(int operand1, int operand2){
	if (operand1 > operand2) {
		return true;
	}
	else 
		return false;
}

DescendingArrayList::DescendingArrayList() : ArrayList() {
	cout << "Empyt desc array list created" << endl;
}

DescendingArrayList::DescendingArrayList(int size) : ArrayList(size) {
	cout << "Desc array list of size " << size << " created" << endl;
}

string DescendingArrayList::getName() {
	return "Descending array List"; 
}

bool DescendingArrayList::directionOperator(int operand1, int operand2){
	if (operand1 < operand2) {
		return true;
	}
	else 
		return false;
}

