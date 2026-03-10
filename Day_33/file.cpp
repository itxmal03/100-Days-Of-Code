#include <iostream>
using namespace std;

/* this pointer is automaticaly created to point to calling object this is
primarily used to indicate data members of class to make diff with constructor parameters and it is only used in constructor
 */


class Student
{
private:
    int marks;

public:
    Student(int marks)
    {
        this->marks = marks;
    }

    // copy constructor
    Student(Student &std)
    {
        cout << "hi i am custom copy constructor!!!!!\n";
        this->marks = std.marks;
    }

    int getInfo()
    {
        return marks;
    }
};

int main()
{
    Student s1(66.5);

    //  Student s2(s1); // default copy contructor is called - invoked
    // cout << s2.getInfo() << endl;


    Student s3(s1);   //now it will call our custom copy constructor 
    cout << s3.getInfo() << endl;
    return 0;
}
