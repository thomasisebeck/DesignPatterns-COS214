#ifndef OVERLOADINGSUPER_H
#define OVERLOADINGSUPER_H
#include <string>

class OverloadingSuper {
private:
	std::string name;
public:
	OverloadingSuper();
	OverloadingSuper(std::string);
	std::string getName();
	virtual void print();
	virtual ~OverloadingSuper();
};

#endif

