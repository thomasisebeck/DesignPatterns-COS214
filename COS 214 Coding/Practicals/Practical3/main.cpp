#include <iostream>
#include <iomanip>

#include "Confectionary.h"
#include "LindtFactory.h"
#include "CadburyFactory.h"
#include "NestleFactory.h"
#include "GiftBasket.h"
#include "AddOn.h"

#include "BattleState.h"
#include "AgileBattleState.h"
#include "NormalBattleState.h"
#include "StrongBattleState.h"
#include "Pokemon.h"
#include "AttackPlayStyle.h"
#include "PhysicalAttackPlayStyle.h"
#include "RunPlayStyle.h"
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

    cout << setprecision(2) << cost << endl;

    if (cost == 0)
        cout << "=============== BASKET CONTENTS ===============" << endl;

    if (beg != end) {
        cout << (*beg)->getDescription();
        cost += (*beg)->getPrice();
        cout << endl << endl;
        printList(++beg, end, cost);
    } else {
        cout << ".................." << endl;
        cout << "TOTAL COST: R" << fixed << setprecision(2) << cost << endl;
        cout << "===============================================" << endl << endl << endl;

    }
}

void staticDecorator() {
    cout << "Choose the number of products to create (1 to 10): " << endl;
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
    delete [] ProductArray;
}

void printBaskets(GiftBasket* currentBasket){
    if (currentBasket == nullptr) return ;

    currentBasket->print();
    printBaskets(currentBasket->getNext());
}

double calculatePrice(GiftBasket* currentBasket, double price){
    if (currentBasket == nullptr)
        return price;

    return calculatePrice(currentBasket->getNext(), price + currentBasket->getPrice());
}

void dynamicDecorator() {
    Confectionary* Product;
    ConfectionaryFactory* Factory;

    int manufacturer = 1;

    bool firstItem = true;

    GiftBasket* basket = nullptr;

    while (manufacturer > 0) {
        cout << "Choose a manufacturer: " << endl;
        cout << "1. Cadbury" << endl;
        cout << "2. Lindt" << endl;
        cout << "3. Nestle" << endl;
        if (!firstItem)
            cout << "0. Exit and go to add-ons" << endl;

        if (!firstItem)
            manufacturer = validateInput(0, 3);
        else
            manufacturer = validateInput(1,3);

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
        //only one gift basket
        cout << ">> added item to basket << " << endl << endl;

        if (firstItem) {
            firstItem = false;
            basket = new GiftBasket(Product);
        }
        else {
            basket = new GiftBasket(basket, Product);
        }

    }

    int addons = 1;

    while (addons > 0) {
        cout << "Choose an add-on: " << endl;
        cout << "1. Ribbon" << endl;
        cout << "2. Note" << endl;
        cout << "3. Card" << endl;
        cout << "4. Flower" << endl;
        cout << "5. Valentines day discount (-5%)" << endl;
        cout << "6. Mothers day discount (-3.5%)" << endl;
        cout << "7. Spring day discount (-7%)" << endl;
        cout << "0. Exit and get total" << endl;

        addons = validateInput(0, 7);

        double total = calculatePrice(basket, 0.00);

        if (addons <= 0) {
            addons = 0;
            break; //exit the loop and print
        }

        double discount = 0.00;

        bool hasNote = false;
        bool hasCard = false;

        if (addons >= 5 && addons <= 7) { //adding a discount
            //check if a discount has already been applied
            if (basket->hasDiscount())
                cout << "You have already applied a discount" << endl;
            else {
                switch (addons) {
                    case 5: //-5%
                        discount = 0.05;
                        Product = new AddOn(((total - total * (1 - 0.05)) * -1), "Valentines day discount", "-5%");
                        basket = new GiftBasket(basket, Product);
                        break;
                    case 6: //-3.5%
                        discount = 0.35;
                        Product = new AddOn(((total - total * (1 - 0.035)) * -1), "Mothers day discount", "-3.5%");
                        basket = new GiftBasket(basket, Product);
                        break;
                    case 7: //-7%
                        discount = 0.07;
                        Product = new AddOn(((total - total * (1 - 0.07)) * -1), "Valentines day discount", "-7%");
                        basket = new GiftBasket(basket, Product);
                }
            }
        } else { //adding something that costs money
            string memVar = "";
            switch (addons) {
                case 1: //Ribbon
                    //Disount not allowed
                    cout << "Enter the color of the ribbon: ";
                    cin.ignore();
                    getline(cin, memVar);
                    Product = new AddOn(7.75, "Ribbon Color", memVar);
                    basket = new GiftBasket(basket, Product);
                    break;
                case 2: //Note
                    if (!hasNote) {
                        //Free
                        cout << "Enter message: ";
                        cin.ignore();
                        getline(cin, memVar);
                        Product = new AddOn(0, "Note", memVar);
                        basket = new GiftBasket(basket, Product);
                        hasNote = true;
                    }
                    else
                        cout << "You have already written a note." << endl;
                    break;
                case 3: //Card
                    if (!hasCard) {
                        //Discount allowed
                        cout << "Enter message: ";
                        cin.ignore();
                        getline(cin, memVar);
                        Product = new AddOn(25.90 - (25.95 * discount), "Card", memVar);
                        basket = new GiftBasket(basket, Product);
                        hasCard = true;
                    }
                    else
                        cout << "You have already written a card." << endl;
                    break;
                case 4: //Flower
                    //Discount allowed
                    cout << "Enter the type/variety of the flower: ";
                    cin.ignore();
                    getline(cin, memVar);
                    Product = new AddOn(3.99 - (3.99 * discount), "Flower type", memVar);
                    basket = new GiftBasket(basket, Product);
            }
        }

    }

   printBaskets(basket);

   double total = calculatePrice(basket, 0.00);

   cout << endl << "=======================" << endl;
   cout         << "TOTAL: R" << fixed << setprecision(2) << total << endl;
   cout         << "=======================" << endl;
}

void statePattern() {

    //std::string name, int HP, int damage, PlayStyle* initialPlaystyle

    PlayStyle* AttackStyle = new AttackPlayStyle;
    PlayStyle* PhysicalAttackStyle = new PhysicalAttackPlayStyle;
    PlayStyle* RunStyle = new RunPlayStyle;

    //Initialise with agile state
    Pokemon Pikachu("Pikachu", 10, 3, AttackStyle);
    Pokemon Vulpix("Vulpix", 15, 4, PhysicalAttackStyle);

    while (Pikachu.getHP() > 0 && Vulpix.getHP() > 0) {
        cout << "Select play style for " << Pikachu.getName() << ":" << endl;
        cout << "1. Attack" << endl;
        cout << "2. Physical Attack" << endl;
        cout << "3. Run" << endl;
        int pikaPlay = validateInput(1, 3);

        cout << "Select play style for " << Vulpix.getName() << ":" << endl;
        cout << "1. Attack" << endl;
        cout << "2. Physical Attack" << endl;
        cout << "3. Run" << endl;
        int vulPlay = validateInput(1, 3);

        switch (pikaPlay) {
            case 1:
                Pikachu.selectPlayStyle(new AttackPlayStyle());
                break;
            case 2:
                Pikachu.selectPlayStyle(new PhysicalAttackPlayStyle());
                break;
            case 3:
                Pikachu.selectPlayStyle(new RunPlayStyle());
                break;
        }

        switch (vulPlay) {
            case 1:
                Vulpix.selectPlayStyle(new AttackPlayStyle());
                break;
            case 2:
                Vulpix.selectPlayStyle(new PhysicalAttackPlayStyle());
                break;
            case 3:
                Vulpix.selectPlayStyle(new RunPlayStyle());
                break;
        }

        cout << "Select battle state style for " << Pikachu.getName() << ":" << endl;
        cout << "1. Normal" << endl;
        cout << "2. Agile" << endl;
        cout << "3. Strong" << endl;
        pikaPlay = validateInput(1, 3);

        cout << "Select battle state style for " << Vulpix.getName() << ":" << endl;
        cout << "1. Normal" << endl;
        cout << "2. Agile" << endl;
        cout << "3. Strong" << endl;
        vulPlay = validateInput(1, 3);

        switch (pikaPlay) {
            case 1:
                Pikachu.selectBattleState(new NormalBattleState());
                break;
            case 2:
                Pikachu.selectBattleState(new AgileBattleState());
                break;
            case 3:
                Pikachu.selectBattleState(new StrongBattleState());
        }

        switch (vulPlay) {
            case 1:
                Vulpix.selectBattleState(new NormalBattleState());
                break;
            case 2:
                Vulpix.selectBattleState(new AgileBattleState());
                break;
            case 3:
                Vulpix.selectBattleState(new StrongBattleState());
        }

        cout << "^^^^^^^^^^^^^^ BATTLE STARTED ^^^^^^^^^^^^^^" << endl;
        Pikachu.attack(Vulpix);
        cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;

    }


}

int main() {

    //DO UML'S and questions!!!!!

    //------------- STATIC IMPLEMENTATION -----------//

    //staticDecorator();

    //------------- DYNAMIC IMPLEMENTATION -----------//

    dynamicDecorator();

    //----------------- POKEMON CLASS ---------------//

    //statePattern();

    return 0;
}

