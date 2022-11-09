#include <iostream>
#include <list>
using namespace std;

class Mercury;
class Mars;
class Saturn;
class Planet;

class Explorer {
public:
    virtual void visit(Mercury* mercury) = 0;
    virtual void visit(Mars* mars) = 0;
    virtual void visit(Saturn* saturn) = 0;

    virtual void visit(Planet* planet) {
        cout << "Oh no! landed on an unknown planet." << endl;
    }
    virtual ~Explorer()=default;
};

//planet interface
class Planet {
protected:
    bool plantsWatered;
    string item;
public:
    Planet() { plantsWatered = false; }
    void waterPlants() { plantsWatered = true; }
    bool getWateredStatus() { return plantsWatered; }
    string getItem() { return item; }
    //accept calls visit on the appropriate subclass
    virtual void accept(Explorer* explorer) = 0;
    virtual ~Planet() {}
};

//planet objects that we will be visiting
class Mercury: public Planet {
public:
    Mercury() {
        this->item = "Magma Rock";
    }
    virtual void accept(Explorer* explorer) {
        explorer->visit(this);
    }
    virtual ~Mercury(){};
};

class Mars: public Planet {
public:
    Mars() {
        this->item = "Martian Rock";
    }
    virtual void accept(Explorer* explorer) {
        explorer->visit(this);
    }
    virtual ~Mars(){};
};

class Saturn: public Planet {
public:
    Saturn() {
        this->item = "Ring Rock";
    }
    virtual void accept(Explorer* explorer) {
        explorer->visit(this);
    }
    virtual ~Saturn(){}
};

class RockCollector: public Explorer {
private:
    std::list<string> collectedItems;
public:
    virtual void visit(Mercury* mercury) {
        collectedItems.push_back(mercury->getItem());
    }
    virtual void visit(Mars* mars) {
        collectedItems.push_back(mars->getItem());
    }
    virtual void visit(Saturn* saturn) {
        collectedItems.push_back(saturn->getItem());
    }
    std::list<string> getCollection() {
        return collectedItems;
    }

};

class LifeExplorer: public Explorer {
public:
    virtual void visit(Mercury* mercury) {
        mercury->waterPlants();
        cout << "Watering Mercury's plants" << endl;
    }
    virtual void visit(Mars* mars) {
        mars->waterPlants();
        cout << "Watering Mars' plants" << endl;
    }
    virtual void visit(Saturn* saturn) {
        saturn->waterPlants();
        cout << "Watering Saturn's plants" << endl;
    }
    virtual ~LifeExplorer()= default;
};

int main() {

    list<Planet*> toVisit;
    toVisit.push_back(new Mercury());
    toVisit.push_back(new Mars());
    toVisit.push_back(new Saturn());

    cout << "Before visiting..." << endl;
    list<Planet*>::iterator iter;
    for (iter = toVisit.begin(); iter != toVisit.end(); iter++)
        cout << "Watered: " << (*iter)->getWateredStatus() << endl;

    //create a life explorer
    Explorer* explorer = new LifeExplorer();

    //visit each planet
    for (iter = toVisit.begin(); iter != toVisit.end(); iter++)
       (*iter)->accept(explorer);

    cout << "After visiting..." << endl;
    for (iter = toVisit.begin(); iter != toVisit.end(); iter++)
        cout << "Watered: " << (*iter)->getWateredStatus() << endl;

    delete explorer;

    Explorer* geologist = new RockCollector();

    for (iter = toVisit.begin(); iter != toVisit.end(); iter++)
        (*iter)->accept(geologist);

    std::list<string> collection = dynamic_cast<RockCollector*>(geologist)->getCollection();
    std::list<string>::iterator collIter;

    for (collIter = collection.begin(); collIter != collection.end(); collIter++)
        cout << "Collected rock: " << (*collIter) << endl;

    delete geologist;

    for (iter = toVisit.begin(); iter != toVisit.end(); iter++)
        delete (*iter);

    return 0;

}
