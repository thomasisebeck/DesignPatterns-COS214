#include <iostream>

#include "AbstractionStack.h"
#include "RA_HanoiStack.h"
#include "RA_LIFOStack.h"
#include "RA_WackStack.h"

#include "MyStackImplementor.h"
#include "MyListImplementor.h"

using namespace std;

int main() {

    //////////// Hanoi Stack ////////////

    AbstractionStack* hanoi = new RA_HanoiStack(ARRAY);

    for (int i = 20; !hanoi->isFull(); i--)
        hanoi->push(i);

    while (!hanoi->isEmpty())
        cout << "hanoi [" << hanoi->pop() <<  "]" << endl;

    delete hanoi;

    ///////////// LIFO Stack /////////////

    AbstractionStack* lifo = new RA_LIFOStack(LIST);

    for (int i = 0; i < 10; i++)
        lifo->push(rand() % 100);

    while (!lifo->isEmpty())
        cout << "lifo [" << lifo->pop() << "]" << endl;

    delete lifo;

    return 0;

}