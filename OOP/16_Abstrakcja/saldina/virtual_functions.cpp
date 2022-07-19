#include<iostream>
using namespace std;

class Instrument {
public:
    virtual void MakeSound() {
        cout << "Instrument playing.." << endl;
    }
};

class Accordion : public Instrument {
public:
    void MakeSound() {
        cout << "Accordion playing.." << endl;
    }
};

class Piano : public Instrument {

};

int main()
{
    Instrument* instrument1 = new Accordion();
    instrument1->MakeSound();

    Instrument* instrument2 = new Piano();
    instrument2->MakeSound();

    return 0;
}