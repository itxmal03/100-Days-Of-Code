#include <iostream>
using namespace std;

/*
encapsulation
wrapping data memebers and member functions inside a single unit called class
*/

/*
  Constructor
  a special function
  class can have many constructors but parameters must be diff , this is also called constructor overloading
*/

class Student
{
private:
    float marks;

public:
    string studentName;
    // non parameterized or default conrstructor automatically called on creation of object , can also be used to give default values
    Student()
    {
        cout << "Default construcor called" << endl;
    }

    // paramterized constructor
    Student(float m)
    {
        marks = m;
    }

    void getInfo()
    {
        cout << marks << endl;
    }
};

int main()
{
    Student s1 = Student(56);
    Student s2(88);
    s1.getInfo();
    s2.getInfo();
    return 0;
}