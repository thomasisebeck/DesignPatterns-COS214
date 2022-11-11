#include <iostream>
using namespace std;

//Product
class House  {
private :
    string basement;
    string structure;
    string roof;
    string interior;
public:
    void setBasement(string basement) {
        this->basement = basement;
    }
    void setStructure(string structure){
        this->structure = structure;
    }
    void setRoof(string roof) {
        this->roof = roof;
    }
    void setInterior(string interior) {
        this->interior = interior;
    }
};

//Builder
class HouseBuilder {
public:
    virtual void buildBasement() = 0;
    virtual void buildStructure() = 0;
    virtual void buildRoof() = 0;
    virtual void buildInterior() = 0;
    virtual House* getHouse() = 0;
    virtual ~HouseBuilder()=default;
};

//Concrete Builder
class IglooBuilder: public HouseBuilder {
private:
    House* myHouse;
public:
    IglooBuilder() {
        myHouse = new House;
    }
    void buildBasement() {
        cout << "buildBasement() invoked in IglooBuilder" << endl;
        myHouse->setBasement("Ice bars");
        cout << "buildBasement() returns in IglooBuilder" << endl;
    }
    virtual void buildStructure() {
        cout << "buildStructure() invoked in IglooBuilder" << endl;
        myHouse->setStructure("Ice blocks");
        cout << "buildStructure() returns in IglooBuilder" << endl;
    }
    virtual void buildRoof() {
        cout << "buildRoof() invoked in IglooBuilder" << endl;
        myHouse->setRoof("Ice dome");
        cout << "buildRoof() returns in IglooBuilder" << endl;
    }
    virtual void buildInterior() {
        cout << "buildInterior() invoked in IglooBuilder" << endl;
        myHouse->setInterior("Ice carvings");
        cout << "buildInterior() returns in IglooBuilder" << endl;
    }
    virtual House* getHouse() {
        cout << "getHouse() invoked in IglooBuilder" << endl;
        cout << "getHouse() returns in IglooBuilder" << endl;
        return myHouse;
    }
    virtual ~IglooBuilder() {
        delete myHouse;
    }
};

//Director
class Engineer {
private:
    HouseBuilder* houseBuilder; //can be igloo-builder
public:
    Engineer(HouseBuilder* houseBuilder) {
        this->houseBuilder = houseBuilder;
    }
    House* getHouse() {
        //asks the builder to return the product
        cout << "getHouse() invoked in Engineer" << endl;
        cout << "getHouse() returns in Engineer" << endl;
        return houseBuilder->getHouse();
    }
    void constructHouse() {
        cout << "constructHouse() invoked in Engineer" << endl;
        //asks the builder to build each part
        cout << "Engineer calls buildBasement()" << endl;
        houseBuilder->buildBasement();
        cout << "Engineer calls buildInterior()" << endl;
        houseBuilder->buildInterior();
        cout << "Engineer calls buildRoof()" << endl;
        houseBuilder->buildRoof();
        cout << "Engineer calls buildStructure()" << endl;
        houseBuilder->buildStructure();
        cout << "constructHouse() returns in Engineer" << endl;
    }
    ~Engineer() {
        delete houseBuilder;
    }
};

//client
int main() {
    //pass the builder to the director
    Engineer* director = new Engineer(new IglooBuilder);

    director->constructHouse();
    House* myHouse = director->getHouse();

    delete director;
}
