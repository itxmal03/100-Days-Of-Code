#include <iostream>
using namespace std;

class Student; // froward decalration

class Teacher
{
private:
    string name = "Sir Adeel";

public:
    // void setName(string name)
    // {
    //     this->name = name;
    // }

    Teacher()
    {
        cout << "Teacher constructor called " << endl;
    }

    string getTeacherName()
    {
        return name;
    }

    ~Teacher()
    {
        cout << "Teacher destructor called " << endl;
    }

    void printTeacherFunction(Student &s);
};

class Student
{
private:
    string studentName = "Ali";

public:
    // void setName(string name)
    // {
    //     this->name = name;
    // }

    Student()
    {
        cout << "student constructor called " << endl;
    }

    string getName()
    {
        return studentName;
    }

    void func(Teacher &t)
    {
        cout << "Student: " << studentName << "  taught by:  " << t.getTeacherName() << endl;
    }

    ~Student()
    {
        cout << "student destructor called " << endl;
    }
};

void Teacher::printTeacherFunction(Student &s)
{
    cout << "Teacher: " << name << "  teaches    " << s.getName() << endl;
}

int main()
{
    Teacher t;
    Student s;
    t.printTeacherFunction(s);

    return 0;
}

// ASSOCIATION
