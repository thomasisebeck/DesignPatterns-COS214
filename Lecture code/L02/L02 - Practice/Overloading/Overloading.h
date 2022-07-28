#ifndef OVERLOADING_H
#define OVERLOADING_H
#include "OverloadingSuper.h"
#include <string>

class Overloading : public OverloadingSuper {
	private: 
		int numWheels; 
	public: 
		Overloading(); 
		Overloading(std::string);
		void addWheel(int); 
		void addWheel(); 
		int getNumWheels();
		virtual ~Overloading();

};

#endif

