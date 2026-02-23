#include <iostream>
using namespace std;

class Teacher
{
private:
    double salary;

public:
    string name;
    string dept;

    // setter method is used to set value of private members because we can't access them outside the class
    void setSalary(float s)
    {
        salary = s;
    }

    // getter method is used to get value of private members because we can't access them outside the class
    double getSalary()
    {
        return salary;
    }
};

int main()
{
    Teacher t1;
    t1.dept = "SCIT";
    t1.name = "Sir Abdul Hanan";
    t1.setSalary(9544.6);
    cout << t1.getSalary() << endl;

    return 0;
}