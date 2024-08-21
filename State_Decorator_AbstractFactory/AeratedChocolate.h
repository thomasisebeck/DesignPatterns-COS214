#ifndef COS214_AERATEDCHOCOLATE_H
#define COS214_AERATEDCHOCOLATE_H
#include "Confectionary.h"
#include <string>

class AeratedChocolate: public Confectionary { //PARENT CONCRETE PRODUCT (SPECIALISED BELOW)
private:
    int bubblespccm;
public:
    AeratedChocolate(std::string manufacturer, double price, int bubblespccm)
            : Confectionary(manufacturer, price, "Aerated") {
        this->bubblespccm = bubblespccm;
    }
    virtual std::string getDescription() {
        std::string addTo = Confectionary::getDescription();
        addTo = addTo + "bubbles/cm^3: " + to_string(bubblespccm);
        return addTo;
    }
};

#endif
