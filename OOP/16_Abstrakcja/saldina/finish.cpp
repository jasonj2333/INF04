//https://youtu.be/T8f4ajtFU9g

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

class Guitar : public Instrument {
public:
    void MakeSound() {
        cout << "Guitar playing.." << endl;
    }
};

int main()
{
    Instrument* instrument1 = new Accordion();
    //instrument1->MakeSound();

    Instrument* instrument2 = new Piano();
    //instrument2->MakeSound();

    Instrument* instrument3 = new Guitar();
    //instrument3->MakeSound();

    Instrument* instruments[3] = { instrument1, instrument2, instrument3 };

    for (Instrument* instrument : instruments) {
        instrument->MakeSound();
    }


    return 0;
}