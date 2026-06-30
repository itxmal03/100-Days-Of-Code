#include <iostream>
using namespace std;

class Student
{
private:
    string studentName;
    int roll;
    static int totalStudent;
    const double salary = 100000;

public:
    Student()
    {
        totalStudent++;
        cout << ">>>>>>Constuctor called!!!!!!" << endl;
        cout << "Total students: " << totalStudent << endl;
    }

    ~Student()
    {
        cout << ">>>>>>Destuctor called!!!!!!" << endl;
    }

    void setData(string n, int r)
    {
        studentName = n;
        roll = r;
    }

    void setName(string n)
    {
        studentName = n;
    }

    void setRoll(int r)
    {
        roll = r;
    }

    string getName()
    {
        return studentName;
    }

    int getRoll()
    {
        return roll;
    }

    static int getTotalStudents()
    {
        return totalStudent;
    }
};

int Student::totalStudent = 0;

int main()
{
    Student s1;

    s1.setName("afzal");
    s1.setRoll(9);

    cout << "NAME: " << s1.getName() << endl;
    cout << "Roll: " << s1.getRoll() << endl;

    Student s2;
    s2.setData("tyu", 990);
    cout << "name of second student:" << s2.getName() << endl;
    cout << "roll of second student: " << s2.getRoll() << endl;

    cout << "total students are: " << Student::getTotalStudents() << endl;

    return 0;
}