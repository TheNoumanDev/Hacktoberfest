
#include <iostream>
using namespace std;

class Student
{
    string name;
    int num;
public:
    // default constructor
    Student()
    {
        cout << " object of this class is created.";
    }

    // paramaterized constructor
    Student(string n,int a;)
    {
        name = n;
        num=a;
    }

    // or

    Student(string name) : name(name) {} // another way of initializing

    // Copy constructor
    Student(Student& const n,Student &const a)
    {
        this->name=n;
        this->num=a;
    }

    ~Student()
    {
        cout << "object destruction complete!"<<end;
    }
};
