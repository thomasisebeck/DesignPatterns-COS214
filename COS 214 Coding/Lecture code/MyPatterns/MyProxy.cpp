#include <iostream>
using namespace std;

class Driver {
private:
    int age;
public:
    Driver(int age) { this->age = age; }
    int getAge() { return age; }
};
class CarInterface{
public:
    virtual void drive() = 0;
};

class Car: public CarInterface {
public:
    void drive() {
        cout << "Car has been driven..." << endl;
    }
};

class CarProxy: public CarInterface {
private:
    Driver* driver;
    Car* myCar;
public:
    CarProxy(Driver* driver) {
        this->driver = driver;
        myCar = new Car;
    }
    void drive() {
        if (driver->getAge() >= 18)
            myCar->drive();
        else
            cout << "You are too young to drive." << endl;
    }
    ~CarProxy() {
        delete driver;
        delete myCar;
    }
};

int main() {

    CarProxy myProxy(new Driver(21));
    myProxy.drive();



    return 0;
}