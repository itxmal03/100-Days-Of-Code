#include <iostream>
using namespace std;

class Student
{
public:
    string name;
    double *cgpa;
    int roll;

    Student(string n, double c)
    {
        this->name = n;
        (*this).cgpa = new double;
        *cgpa = c;
    }

    Student(int r)
    {
        this->roll = r;
    }

    // user defined copy construcor

    void show()
    {
        cout << "STUDENT NAME: " << name << endl;
        cout << "CGPA: " << *cgpa << endl;
    }

    void show2()
    {
        cout << "ROLL: " << roll << endl;
    }
};

int main()
{
    // Student s("Aftab", 9.8);
    // s.show();
    // Student s2(s);
    // *s2.cgpa = 5.5;
    // s2.show();

    // Student r(8);
    // r.show2();
    // r.roll = 10;
    // r.show2();
    // Student r2(r);
    // r2.show2();
    // r.show2();
    // r.roll = 90;
    // r2.show2();
    // r.show2(); 
    return 0;
}