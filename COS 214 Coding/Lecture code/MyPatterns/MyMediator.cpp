#include <iostream>
using namespace std;

class BaseComponent;
class Mediator {
public:
    virtual void notify(string event) = 0;
    virtual void sendEnc(string msg, BaseComponent* reciever) = 0;
};

class BaseComponent {
protected:
    Mediator* myMediator;
public:
    BaseComponent(Mediator* myMediator = nullptr) {
        this->myMediator = myMediator;
    }
    void setMediator(Mediator* mediator) {
        this->myMediator = mediator;
    }
    void recieveEnc(string msg) {
        cout << "I recieved: ";
        string recieved = "";
        for (int i = 0; i < msg.length(); i++)
            recieved += char(int(msg[i]) - 1);
        cout << recieved << endl;
    }
};

class Component1: public BaseComponent {
public:
    void doMyAction() {
        cout << "C1 does action" << endl;
        this->myMediator->notify("A");
    }
    void reactToAction() {
        cout << "C1 reacts to action" << endl;
    }
};

class Component2: public BaseComponent {
public:
    void doMyAction() {
        cout << "C2 does action" << endl;
        this->myMediator->notify("B");
    }
    void reactToAction() {
        cout << "C2 reacts to action" << endl;
    }
};

class ConcreteMediator: public Mediator {
private:
    Component1* c1;
    Component2* c2;
public:
    ConcreteMediator(Component1* c1, Component2* c2) {
        this->c1 = c1;
        this->c1->setMediator(this);

        this->c2 = c2;
        this->c2->setMediator(this);
    }
    virtual void notify(string event) {
        if (event == "A")
            this->c2->reactToAction();
        else if (event == "B") {
            this->c1->reactToAction();
            this->c2->reactToAction();
        }
    }
    virtual void sendEnc(string msg, BaseComponent* reciever){
        string newMessage = "";
        for (int i = 0; i < msg.length(); i++)
            newMessage += char(int(msg[i]) + 1);
        reciever->recieveEnc(newMessage);
    }

};

int main() {

    Component1* c1 = new Component1;
    Component2* c2 = new Component2;

    Mediator* mediator = new ConcreteMediator(c1, c2);

    c1->doMyAction();
    c2->doMyAction();

    mediator->sendEnc("C1 will receive this!", c1);
    mediator->sendEnc("C2 will receive this!", c2);

    delete c1;
    delete c2;
    delete mediator;

    return 0;
}

