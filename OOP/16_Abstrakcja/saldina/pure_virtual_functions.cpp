#include<iostream>
using namespace std;

class Instrument { //Abstract class
public:
    virtual void MakeSound() = 0; //Pure virtual functions
};

class Accordion : public Instrument {
public:
    void MakeSound() {
        cout << "Accordion playing.." << endl;
    }
};

class Piano : public Instrument {
public:
    void MakeSound() {
        cout << "Piano playing.." << endl;
    }
};

int main()
{
    Instrument* instrument1 = new Accordion();
    instrument1->MakeSound();

    Instrument* instrument2 = new Piano();
    instrument2->MakeSound();

    return 0;
}