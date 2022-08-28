#include <iostream>
#include <iomanip>
#include "Confectionary.h"
#include "LindtFactory.h"
#include "CadburyFactory.h"
#include "NestleFactory.h"
#include "GiftBasket.h"
using namespace std;

int validateInput(int low, int high) {
    cout << "-> ";
    int option;
    cin >> option;
    cout << endl;

    while (option < low || option > high) {
        cout << "Choose valid option -> ";
        cin >> option;
        cout << endl;
    }

    return option;
}

void printList(std::list<Confectionary*>::iterator beg, std::list<Confectionary*>::iterator end, double cost) {

    if (cost == 0)
        cout << "=============== BASKET CONTENTS ===============" << endl;

    if (beg != end) {
        cout << (*beg)->getDescription();
        cost += (*beg)->getPrice();
        cout << endl << endl;
        printList(++beg, end, cost);
    } else {
        cout << ".................." << endl;
        cout << "TOTAL COST: R" << setprecision(2) << cost << endl;
        cout << "===============================================" << endl << endl << endl;

    }
}

int main() {

    //------------- STATIC IMPLEMENTATION -----------//

   /* cout << "Choose the number of products to create (1 to 10): " << endl;
    int numProducts = validateInput(1, 10);

    Confectionary* Product;
    ConfectionaryFactory* Factory;

    Confectionary** ProductArray = new Confectionary * [numProducts];

    for (int i = 0; i < numProducts; i++) {
        cout << endl << "Creating product " << i + 1 << " of " << numProducts <<  "..." << endl << endl;

        cout << "Choose a manufacturer: " << endl;
        cout << "1. Cadbury" << endl;
        cout << "2. Lindt" << endl;
        cout << "3. Nestle" << endl;

        int manufacturer = validateInput(1,3);

        //Create the factory

        Factory = nullptr;

        switch (manufacturer) {
            case 1:
                Factory = new CadburyFactory;
                break;
            case 2:
                Factory = new LindtFactory;
                break;
            case 3:
                Factory = new NestleFactory;
        }

        //create the product

        cout << "Choose a product type: " << endl;
        cout << "1. Regular" << endl;
        cout << "2. Aerated" << endl;

        int type = validateInput(1,2);

        //object with price == -1
        Product = new DoesNotExist(false);

        while (Product->getPrice() == -1) {
            if (type == 1) { //Regular
                cout << "1. Slab" << endl;
                cout << "2. Mini bar" << endl;
                int slab = validateInput(1, 2);
                Product = Factory->createRegular(slab == 1);
            } else { //Aerated
                cout << "Enter bubbles per cm^3: ";
                int bubbles;
                cin >> bubbles;
                cout << endl;
                Product = Factory->createAerated(bubbles);
            }

            if (Product->getPrice() == -1) { //nonexistent
                cout << "Choose a product type: " << endl;
                cout << "1. Regular" << endl;
                cout << "2. Aerated" << endl;
                type = validateInput(1,2);
            }
        }

        ProductArray[i] = Product;

        //validated input, always created a factory
        delete Factory;

    }

    cout << "================================== " << endl
         << "You created the following products: " << endl << endl;

    for (int i = 0; i < numProducts; i++) {
        cout << ProductArray[i]->getDescription() << endl << endl;
    }

    cout << "================================== " << endl;

    for (int i = 0; i < numProducts; i++)
        delete ProductArray[i];
    delete [] ProductArray;*/

    //------------- DYNAMIC IMPLEMENTATION -----------//

    Confectionary* Product;
    ConfectionaryFactory* Factory;

    GiftBasket basket;

    int manufacturer = 1;

    while (manufacturer > 0) {
        cout << "Choose a manufacturer: " << endl;
        cout << "1. Cadbury" << endl;
        cout << "2. Lindt" << endl;
        cout << "3. Nestle" << endl;
        cout << "0. Exit and get total" << endl;

        manufacturer = validateInput(0, 4);

        if (manufacturer <= 0) {
            manufacturer = 0;
            break; //exit the loop and print
        }

        //Create the factory

        Factory = nullptr;

        //Input has to be 1 to 3
        switch (manufacturer) {
            case 1:
                Factory = new CadburyFactory;
                break;
            case 2:
                Factory = new LindtFactory;
                break;
            case 3:
                Factory = new NestleFactory;
        }

        cout << "Choose a product type: " << endl;
        cout << "1. Regular" << endl;
        cout << "2. Aerated" << endl;

        int type = validateInput(1,2);

        //object with price == -1
        Product = new DoesNotExist(false);

        while (Product->getPrice() == -1) { //still the nonexistent product
            if (type == 1) { //Regular
                cout << "1. Slab" << endl;
                cout << "2. Mini bar" << endl;
                int slab = validateInput(1, 2);
                Product = Factory->createRegular(slab == 1);
            } else { //Aerated
                cout << "Enter bubbles per cm^3: ";
                int bubbles;
                cin >> bubbles;
                cout << endl;
                Product = Factory->createAerated(bubbles);
            }

            if (Product->getPrice() == -1) { //nonexistent
                cout << "Choose a product type: " << endl;
                cout << "1. Regular" << endl;
                cout << "2. Aerated" << endl;
                type = validateInput(1,2);
            }
        }

        basket.addItem(Product);
        cout << ">> added item to basket << " << endl << endl;

    }

    std::list<Confectionary*> list = basket.getList();
    std::list<Confectionary*>::iterator beg = list.begin();
    std::list<Confectionary*>::iterator end = list.end();

    //cout << (*currentItem)->getDescription() << endl;
    //currentItem = currentItem.operator++();
   // cout << (*currentItem)->getDescription() << endl;

    printList(beg, end, 0);

    return 0;
}