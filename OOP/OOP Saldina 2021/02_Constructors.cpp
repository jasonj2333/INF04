#include<iostream>
using namespace std;

class Employee{
public:
    string Name;
    string Company;
    int Age;

    Employee(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;
    }

    void IntroduceYourself(){
        cout << "Name: " << Name << endl;
        cout << "Company: " << Company << endl;
        cout << "Age: " << Age << endl;
    }
};

int main()
{
    Employee employee1 = Employee("Saldina", "YT-CodeBeauty", 25);
    employee1.IntroduceYourself();

    Employee employee2 = Employee("John", "Amazon", 35);
    employee2.IntroduceYourself();
    return 0;
}