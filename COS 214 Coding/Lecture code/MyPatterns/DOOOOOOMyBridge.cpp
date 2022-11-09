#include <iostream>
using namespace std;

class Device {
private:
    int volume;
    bool enabled;
    string name;
public:
    Device(string name) {
        volume = 0;
        enabled = false;
        this->name = name;
    }
    string getName() {
        return name;
    }
    bool isEnabled() {
        return enabled;
    };
    virtual void enable() {
        enabled = true;
    }
    virtual void disable() {
        enabled = false;
    }
    virtual int getVolume() {
        return volume;
    }
    virtual int setVolume(int v) {
        this->volume = v;
    }
};

class TV: public Device {
public:
    TV() : Device("TV") {
        cout << "Created TV" << endl;
    }
};

class Radio: public Device {
public:
    Radio() : Device("Radio") {
        cout << "Created Radio" << endl;
    }
};



class RemoteControl {
protected:
    //maintain reference to implementation
    Device* device;
public:
    RemoteControl(Device* device) {
        this->device = device;
    }
    void enable() {
        this->device->enable();
    }
    void disable() {
        this->device->disable();
    }
    void volumeUp() {
        if (this->device->isEnabled()) {
            this->device->setVolume(this->device->getVolume() + 1);
            cout << "Incremented volume: " << this->device->getVolume() << endl;
        }
    }
    void volumeDown() {
        if (this->device->isEnabled()) {
            this->device->setVolume(this->device->getVolume() - 1);
            cout << "Decremented volume: " << this->device->getVolume() << endl;
        }
    }
    ~RemoteControl() {
        delete device;
    }
};

class AdvancedRemoteControl: public RemoteControl {
public:
    AdvancedRemoteControl(Device* d) : RemoteControl(d) {}
    void mute() {
        this->device->setVolume(0);
    }
};

int main() {

    AdvancedRemoteControl radioControl(new Radio());

    radioControl.enable();
    radioControl.disable();

    AdvancedRemoteControl tvControl(new TV());

    return 0;
}