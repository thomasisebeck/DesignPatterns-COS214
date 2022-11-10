#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

//forward declare items to visit
class Book;
class Fruit;

class ShoppingVisitor {
public:
    //pass forward declarations as pointers
    void visit(Book* book);
    void visit(Fruit* fruit);
};

class NamesVisitor {
public:
    void visit(Book* book);
    void visit(Fruit* fruit);
};

class ItemElement {
    virtual void accept(ShoppingVisitor* visitor) = 0;
    virtual int getPrice() = 0;
};

//concreteElement
class Book : public ItemElement {
private:
    int price;
    string ISBN;
public:
    Book(int price, string ISBN) : price(price), ISBN(ISBN) {}
    int getPrice() { return price; }
    string getISBN() { return ISBN; }
    virtual void accept(ShoppingVisitor* visitor) {
        visitor->visit(this);
    }
};

class Fruit: public ItemElement {
private:
    string name;
    int cost;
public:
    Fruit(int cost, string name): name(name), cost(cost) {}
    string getName() { return name; }
    int getPrice() { return cost; }
    virtual void accept(ShoppingVisitor* visitor) {
        visitor->visit(this);
    }
};

//Only implement visitor functions after other classes
//have been declared

void ShoppingVisitor::visit(Book *book) {
    int cost;
    if (book->getPrice() > 50)
        cost = book->getPrice() - 5;
    else
        cost = book->getPrice();
    cout << "Book visited with ISBN " << book->getISBN() << " and price R" << cost << endl;
}

void ShoppingVisitor::visit(Fruit *fruit) {
    int cost = fruit->getPrice();
    cout << "Fruit visited with name " << fruit->getName() << " and price R" << cost << endl;
}

int main() {

    const int NUM_ITEMS = 10;

    auto* shoppingVisitor = new ShoppingVisitor;
    auto** bookArray = new Book * [NUM_ITEMS];
    auto** fruitArray = new Fruit * [NUM_ITEMS];

    string  fruitItems [NUM_ITEMS] = {
        "Apple",
        "Pear",
        "Grape",
        "Banana",
        "Apricot",
        "Pineapple",
        "Watermelon",
        "Litchi",
        "Pomegranate",
        "Mango"
    };

    for (int i = 0; i < NUM_ITEMS; i++)
        bookArray[i] = new Book(i * 10 + 10, "00" + to_string(i));

    for (int i = 0; i < NUM_ITEMS; i++)
        fruitArray[i] = new Fruit((rand() % 10 + 1), fruitItems[i]);

    //visit all the fruits and books

    for (int i = 0; i < NUM_ITEMS; i++)
        shoppingVisitor->visit(bookArray[i]);

    for (int i = 0; i < NUM_ITEMS; i++)
        shoppingVisitor->visit(fruitArray[i]);


    for (int i = 0; i < NUM_ITEMS; i++) {
        delete fruitArray[i];
        delete bookArray[i];
    }

    delete [] fruitArray;
    delete [] bookArray;

    delete shoppingVisitor;

    return 0;
}