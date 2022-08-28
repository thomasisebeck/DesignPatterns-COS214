#ifndef COS214_GIFTBASKET_H
#define COS214_GIFTBASKET_H
#include <list>
#include "Confectionary.h"

class GiftBasket {
private:
    Confectionary* toDecorate;
    GiftBasket* nextBasket;
public:

    GiftBasket(Confectionary *toDecorate)  {
        this->toDecorate = toDecorate;
        nextBasket = nullptr;
    }

    GiftBasket(GiftBasket* oldBasket, Confectionary* toDecorate) {
        nextBasket = oldBasket;
        this->toDecorate = toDecorate;
    }

    GiftBasket* getNext() { return nextBasket; }
    double getPrice() { return toDecorate->getPrice(); }

    void print() {
        cout << toDecorate->getDescription() << endl;
    }

    bool hasDiscount() {
        Confectionary* currConfectionary = toDecorate;
        GiftBasket* currBasket = this;

        while (currBasket != nullptr) {
            if (currConfectionary->getPrice() < 0)
                return true;
            currBasket = currBasket->nextBasket;
            if (currBasket != nullptr)
                currConfectionary = currBasket->toDecorate;
        }

        return false;
    }

    ~GiftBasket() {
        delete toDecorate;
    }
};

#endif
