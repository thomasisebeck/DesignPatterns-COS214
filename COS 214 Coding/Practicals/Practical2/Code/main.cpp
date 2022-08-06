#include <iostream>
#include "Snake.h"
using namespace std;

int main() {

    Snake s(10, 2, "Siss", "Wrap Around", "Tail block");
    SquadMember m(10, 1, "Barry");

    s.attack(&m);

    return 0;
}
