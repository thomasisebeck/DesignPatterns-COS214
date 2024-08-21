#ifndef COS214_ADDON_H
#define COS214_ADDON_H
#include <string>
#include "Confectionary.h"

class AddOn: public Confectionary{
private:
    double price;
    std::string memVar;
    std::string memVarName;
public:
    //(string manufacturer, double price, string type
    AddOn(double price, std::string memVarName, std::string memVar): Confectionary(memVar, price, memVarName) {
        this->price = price;
        this->memVarName = memVarName;
        this->memVar = memVar;
        cout << endl << ">> added add-on to basket <<" << endl << endl;
    }

    string getDescription() {
        stringstream strm;

        //print myself
        strm << "---- Add on Details ----" << endl;
        strm << this->memVarName << ": " << this->memVar << endl;
        strm << "price: R" << setprecision(2) << this->price << endl;

        return strm.str();
    }
};

#endif
