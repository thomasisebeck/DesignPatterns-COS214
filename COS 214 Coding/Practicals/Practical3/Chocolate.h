#ifndef COS214_CHOCOLATE_H
#define COS214_CHOCOLATE_H
#include "Confectionary.h"

class Chocolate: public Confectionary { //CHILD CONCRETE PRODUCT
private:
    bool slab;
public:
    Chocolate(std::string manufacturer, double price, bool slab)
            : Confectionary(manufacturer, price, "Bar") {
        //type is bar for nomal chocolate
        this->slab = slab;
    }
    virtual std::string getDescription() {
        std::string addTo = Confectionary::getDescription();
        addTo = addTo + "slab/mini: " +  (this->slab ? "slab" : "mini");
        return addTo;
    }
};

#endif
