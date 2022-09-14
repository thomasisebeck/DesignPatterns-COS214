#include <iostream>
#include <vector>
using namespace std;

struct state {
    int intState;
    bool boolState;
};

class Subject; //forward declare the observer

//interface observer class
class Observer {
protected:
    Subject* subject;
public:
    virtual void update() = 0;
};

class Subject {
private:
    vector<Observer*> observers;
    state myState;
public:
    //need pointers because of incomplete type!
    state getState() {
        return myState;
    }
    void setState(int intState, bool boolState) {
        myState.intState = intState;
        myState.boolState = boolState;
    }
    bool attach(Observer* ob) {
        observers.push_back(ob);
        return true;
    }
    bool detach(Observer* ob) {
        vector<Observer*>::iterator it;
        for (it = observers.begin(); it != observers.end(); it++)
            if (*it == ob) { //found
                observers.erase(it, it + 1);
                return true;
            }
        return false;
    }
    void notify() {
        vector<Observer*>::iterator it;
        for (it = observers.begin(); it != observers.end(); it++)
            (*it)->update();
    }
};

class BoolObserver: public Observer {
private:
public:
    BoolObserver(Subject* s) {
        this->subject = s;
        cout << "Bool observer attaching..." << endl;
        this->subject->attach(this);
    }
    virtual void update() {
        cout << "Bool observer taken note of subjects boolstate: "
             << this->subject->getState().boolState << endl;
    }
};

class IntObserver: public Observer {
private:
public:
    IntObserver(Subject* s) {
        this->subject = s;
        cout << "Int observer attaching..." << endl;
        this->subject->attach(this);
    }
    virtual void update() {
        cout << "Int observer taken note of subjects intstate: "
             << this->subject->getState().intState << endl;
    }
};

int main() {

    Subject* s1 = new Subject;
    s1->setState(1, false);
    Subject* s2 = new Subject;
    s2->setState(2, true);

    //attaches inside the constructor
    IntObserver* oint1 = new IntObserver(s1);
    IntObserver* oint2 = new IntObserver(s2);
    BoolObserver* obool1 = new BoolObserver(s1);
    BoolObserver* obool2 = new BoolObserver(s2);

    s1->setState(3, false);
    s1->notify();
    s2->setState(5, true);
    s2->notify();


    delete s1;
    delete s2;
    delete oint1;
    delete oint2;
    delete obool1;
    delete obool2;

    return 0;
}

