#include <iostream>
using namespace std;

int A(int m, int n) {
    if (m == 0)
        return n + 1;
    else if (m > 0 && n == 0)
        return A(m - 1, 1);
    else if (m > 0 && n > 0)
        return A(m - 1, A(m, n - 1));
}

int main() {

    cout << A(1,2) << endl;

    //runs out of memory

    return 0;
}
