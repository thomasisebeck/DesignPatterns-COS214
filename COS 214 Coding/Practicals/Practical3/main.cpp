#include <iostream>
#include "Confectionary.h"
#include "LindtFactory.h"
#include "CadburyFactory.h"
#include "NestleFactory.h"
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

int main() {

    cout << "Choose a manufacturer: " << endl;
    cout << "1. Cadbury" << endl;
    cout << "2. Lindt" << endl;
    cout << "3. Nestle" << endl;

    int manufacturer = validateInput(1,3);

    //Create the factory

    ConfectionaryFactory* Factory = nullptr;

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
    Confectionary* Product = new DoesNotExist(false);

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


    cout << endl << Product->getDescription() << endl;

    delete Product;
    delete Factory;

    return 0;
}