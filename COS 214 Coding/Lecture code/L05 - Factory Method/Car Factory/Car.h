#ifndef COS214_CAR_H
#define COS214_CAR_H
#include <string>
#include <iostream>
using namespace std;

/////////////// WHEEL TYPES ///////////////

struct Wheels {
    string name;
    int diameter;
    bool grippy;
};

////////////// CAR INTERFACE //////////////

class Car {
public:
    Car(string n, Wheels w);
    void getDetails();
private:
    string name;
    static int _producedCars;
    Wheels wheels;
protected:
    virtual void hoot() = 0;
};

int Car::_producedCars = 0;

Car::Car(string n, Wheels w) {
    name = n;
    wheels = w;
}

void Car::getDetails() {
    cout << "----------------" << endl;
    cout << "Car name: " << this->name << endl;
    cout << "wheel specs: " << endl;
    cout << " - name: " << this->wheels.name << endl;
    cout << " - diameter: " << this->wheels.diameter << endl;
    cout << " - grippy: " << this->wheels.grippy << endl;
    cout << "----------------" << endl;
}

////////////// CARS //////////////

class BMW: public Car {
public:
    BMW(string n, Wheels w);
protected:
    virtual void hoot();
};

BMW::BMW(std::string n, Wheels w): Car(n, w) {}

void BMW::hoot() {
    cout << "BMOOOT" << endl;
}

class Toyota: public Car {
protected:
    virtual void hoot();
};

void Toyota::hoot() {
    cout << "TOOT" << endl;
}

////////////// CAR FACTORY INTERFACE //////////////

class CarFactory {
private:
    string name;
protected:
    virtual Car* produceCar(string carName) = 0;
public:
    string getName();
    void setName(string n);
};

string CarFactory::getName() {return name;}

void CarFactory::setName(string n){ this->name = n; }

/////////////////// CAR FACTORYS /////////////////

class BMWFactory: public CarFactory {
public:
    BMWFactory(string n);
    virtual Car* produceCar(string carName);
};

BMWFactory::BMWFactory(string n) {
    this->setName("[BMW] " + n);
}

Car* BMWFactory::produceCar(string carName) {
    cout << "Creating a BMW..." << endl;
    Wheels w;
    w.name = "BM Racers";
    w.diameter = 130;
    w.grippy = true;
    return new BMW(carName, w);
}

class ToyotaFactory: public CarFactory {
public:
    ToyotaFactory(string n);
    virtual Car* produceCar();
};

ToyotaFactory::ToyotaFactory(string n) {
    name = "[Toyota] " + n;
}

Car* ToyotaFactory::produceCar() {
    cout << "Creating a Toyota..." << endl;

}



#endif
