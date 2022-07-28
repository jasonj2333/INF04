//https://youtu.be/KXDzBglp83M
#include<iostream>
using namespace std;

class EquilateralTriangle {
private:
    float a;
    float circumference;
    float area;
public:
    void setA(float length) {
        a = length;
        circumference = a * 3;
        area = (1.73 * a * a) / 4;
    }

    //friend void PrintResult(EquilateralTriangle);
    friend class Homework;
};

//Friendly function
//void PrintResult(EquilateralTriangle et) {
//    cout << "circumference = " << et.circumference << endl;
//    cout << "area = " << et.area << endl;
//}

class Homework {
public:
    static void PrintResult(EquilateralTriangle et) {
        cout << "circumference = " << et.circumference << endl;
        cout << "area = " << et.area << endl;
    }
};

int main()
{
    EquilateralTriangle et;
    et.setA(3);
    /*Homework h;
    h.PrintResult(et);*/
    Homework::PrintResult(et);
    return 0;
}