#include <iostream>
using namespace std;

// classes -> code reusability

class Car
{
private: // default
    string name, color;
    int speed,distance;
    

public:
    //default constructor
    Car()
    {
    name=" ";
    color=" ";
    speed=0;
    distance=0;
    }
    // Parameterized constructors
    Car(string name, string color, int speed,int distance) : name(name), color(color), speed(speed),distance(distance) {}

    Car(string name, string color, int speed) : name(name), color(color), speed(speed) {}
    void setdistance(int d)
    {
    distance=d;
    }
    int get_travel_time() const;

    // function header
    int get_speed() const;

} Audi("R8", "white", 3,34);

// functions can be defined outside class, provided we have defined its function header in class
int Car::get_travel_time() const;
{
        return distance / speed;
}
int Car ::get_speed()
{
    return speed;
}

int main()
{
    int s;
    cout<<"enter distance"<<endl;
    cin>>s;
    Car Mustang("Mustang", "black", 5);
    Mustang.setdistance(s);
    cout << Mustang.get_travel_time() << "\n";
    cout << Audi.get_travel_time() << "\n";
    cout << "Mustang speed : " << Mustang.get_speed() << "\n";

    return 0;
}
