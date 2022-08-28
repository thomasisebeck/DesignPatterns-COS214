#ifndef COS214_GIFTBASKET_H
#define COS214_GIFTBASKET_H
#include <list>
#include "Confectionary.h"

class GiftBasket: public Confectionary {
private:
    std::list<Confectionary*> items;
public:
    //construct the Confectionary and items using default constructor
    GiftBasket() : Confectionary(), items() {}

    void addItem(Confectionary* item) { items.push_back(item); }

    std::list<Confectionary*> getList() { return items; }

    ~GiftBasket() {
        std::list<Confectionary*>::iterator it;
        for (it = items.begin(); it != items.end(); ++it)
            delete *it;
    }
};

#endif
