#include <iostream>
#include <vector>
using namespace std;

class Student
{

public:
    Student()
    {
        cout << "default constructor called " << endl;
    }
    string name, subject;
    int roll;

    void display()
    {
        cout << name << endl;
        cout << subject << endl;
        cout << roll << endl;
    }
};

struct Student1
{
    string name, subject;
    int roll;

    Student1()
    {
        cout << "default constructor called for struct" << endl;
    }

    void display()
    {
        cout << name << endl;
        cout << subject << endl;
        cout << roll << endl;
    }
};

int main()
{
    // vector<int> v;
    // string name, subject;
    // int roll;
    // cout << "enter name " << endl;
    // cin >> name;
    // cout << "Enter roll number " << endl;
    // cin >> roll;
    // cout << "Enter subject " << endl;
    // cin >> subject;

    // cout << endl;

    // cout << name << endl;
    // cout << roll << endl;
    // cout << subject << endl;

    // Student s;

    // cout << "enter name " << endl;
    // cin >> s.name;
    // cout << "Enter roll number " << endl;
    // cin >> s.roll;
    // cout << "Enter subject " << endl;
    // cin >> s.subject;

    // cout << endl;

    // s.display();

    Student s2;
    // cout << "enter name " << endl;
    // cin >> s2.name;
    // cout << "Enter roll number " << endl;
    // cin >> s2.roll;
    // cout << "Enter subject " << endl;
    // cin >> s2.subject;

    // cout << endl;
    // s2.display();

    Student1 structObj;

    // cout << "name for struct obj" << endl;
    // cin >> structObj.name;
    // cout << "subject for struct obj " << endl;
    // cin >> structObj.subject;
    // cout << "roll for struct obj " << endl;
    // cin >> structObj.roll;

    // structObj.display();

    return 0;
}