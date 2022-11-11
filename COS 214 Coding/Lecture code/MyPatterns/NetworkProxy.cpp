#include <iostream>
using namespace std;

struct image {
    string name;
    int size;
};

class Internet {
private:
    image* images;
public:
    Internet() {
        images = new image[5];

        images[0].name = "Cat";
        images[0].size = 12;

        images[1].name  = "Dog";
        images[1].size = 32;

        images[2].name  = "Pineapple";
        images[2].size = 14;

        images[3].name  = "Meme";
        images[3].size = 10;

        images[4].name  = "CD";
        images[4].size = 9;
    }
    image getImage(int index) {
        if (index > 4 || index < 0) {
            image err;
            err.name = "Invalid index";
            err.size = 0;
            return err;
        }

        return images[index];
    }
    ~Internet() {
        delete [] images;
    }
};

class User {
private:
    int bandwidthLeft;
public:
    User(int bandwidth) {
        this->bandwidthLeft = bandwidth;
    }
    void subtractBandwidth(int toSubtract) {
        bandwidthLeft -= toSubtract;
        if (bandwidthLeft < 0)
            bandwidthLeft = 0;
    }
    int getBandwidthLeft() {
        return bandwidthLeft;
    }
};

class NetworkProxy : public Internet {
public:
    void accessNetwork(User* user, int index) {
        int bandwidthNeeded = getImage(index).size;
        if (bandwidthNeeded > user->getBandwidthLeft()) {
            cout << "Not enough bandwidth left..." << endl;
            return ;
        }

        user->subtractBandwidth(bandwidthNeeded);
        cout << getImage(index).size << "MB used to access " << getImage(index).name << endl;
    }
};

int main() {

    User u1(100);
    User u2(100);

    NetworkProxy proxy;

    proxy.accessNetwork(&u1, 3);
    proxy.accessNetwork(&u2, 4);
    proxy.accessNetwork(&u1, 1);
    proxy.accessNetwork(&u2, 7);

    return 0;
}