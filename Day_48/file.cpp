#include <iostream>
using namespace std;

class Student
{
private:
    string name;
    float cgpa;

    float *pointerCgpa;

public:
    // Student(string n, float c)
    // {
    //     this->name = n;
    //     this->cgpa = c;
    // }

    Student(string n, float &c)
    {
        this->name = n;
        *pointerCgpa = c;
    }

    void show()
    {
        cout << "STUDNET NAME: " << name << endl;
        cout << "STUDENT CGPA: " << cgpa << endl;
    }

    void updateCgpa(float c)
    {
        cgpa = c;
    }
};

int main()
{

    //  Student s1("Ali", 9.3);
    //  Student s2(s1);

    float y = 6;
    float *x = &y;
    // Student s1("Ali", &x);

    // s1.show();
    // cout << endl;
    // s2.show();

    // s2.updateCgpa(5);
    // s2.show();
    // s1.show();
    return 0;
}