#include <iostream>
using namespace std;

class Vehicle
{
private:
    string brandName;

public:
    Vehicle()
    {
        cout << "Constructor of Base class (Vehicle) called---!!!" << endl;
    }
    void setBrandName(string name)
    {
        this->brandName = name;
    }

    string getBrandName()
    {
        return brandName;
    }

    ~Vehicle()
    {
        cout << "Destructor of Base class (Vehicle) called---!!!" << endl;
    }
};

class Car : public Vehicle
{
private:
    int numOfDoors;

public:
    Car()
    {
        cout << "Constructor of Derived class (Car) called---!!!" << endl;
    }
    void setNumOfDoors(int doors)
    {
        this->numOfDoors = doors;
    }
    int getDoors()
    {
        return numOfDoors;
    }

    ~Car()
    {
        cout << "Destructor of Derived class (Car) called---!!!" << endl;
    }
};

int main()
{
    Car c;
    c.setBrandName("My____Car");
    c.setNumOfDoors(4);
    cout << "Brand Name is : " << c.getBrandName() << endl;
    cout << "Number of doors are  : " << c.getDoors() << endl;

    return 0;
}