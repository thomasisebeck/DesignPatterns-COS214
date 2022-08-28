#ifndef COS214_CONFECTIONARY_H
#define COS214_CONFECTIONARY_H
#include <sstream>
#include <string>
using namespace std;

class Confectionary { //PARENT ABSTRACT PRODUCT
private:
    string manufacturer;
    double price;
    string type;
    static int id;
public:
    Confectionary(string manufacturer, double price, string type) {
        id++;
        this->manufacturer = manufacturer;
        this->price = price;
        this->type = type;
    }
    virtual string getDescription() {
        stringstream strm;
        strm << "---- Confectionary Details ----" << endl;
        strm << "manufacturer: " << this->manufacturer << endl;
        strm << "price: " << this->price << endl;
        strm << "type: " << this->type << endl;
        strm << "id: " << this->id << endl;

        return strm.str();
    }
    double getPrice() { return price; }
};

//init the counter to 0
int Confectionary::id = 0;

#endif