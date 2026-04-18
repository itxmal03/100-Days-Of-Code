#include <iostream>
using namespace std;

class Employee
{
private:
    string name;
    int id;
    double salary;
    static int totalEmployee;
    const double tax = 800;
    const int empCode;

public:
    Employee(int c) : empCode(c)
    {
        this->name = "";
        this->id = 0;
        totalEmployee++;
        cout << ">>>>>> Default Employee Constructor called...." << endl;
    }

    Employee(string n, int i, int c) : empCode(c)
    {
        this->name = n;
        this->id = i;
        totalEmployee++;
        cout << ">>>>>>parametized Employee Constructor called...." << endl;
    }

    ~Employee()
    {
        cout << "||||>>>>>>Employee Destructor called---->" << endl;
    }

    void setSalary(double);
    double getSalary() const;

    void setName(string name)
    {
        this->name = name;
    }

    void setId(int id)
    {
        this->id = id;
    }

    int getId() const
    {
        return id;
    }

    string getName() const
    {
        return name;
    }

    void printData()
    {
        cout << "Employee Name is : " << name << endl;
        cout << "id is : " << id << endl;
    }

    static int getTotalEmployee()
    {
        return totalEmployee;
    }

    virtual ~Employee()
    {
        cout << "||||>>>>>>Employee Destructor called---->" << endl;
    };
};

void Employee::setSalary(double s)
{
    this->salary = s;
}

double Employee::getSalary() const
{
    return this->salary;
}

int Employee::totalEmployee = 0;

class Teacher : public Employee
{
private:
    string dept;

public:
    Teacher() : Employee(0)
    {
        this->dept = "";
        cout << ">>>>>Default  Teacher constructor called::::" << endl;
    }

    ~Teacher()
    {
        cout << ">>>Teacher Destructor called::::" << endl;
    }

    Teacher(string name, string dept, int id) : Employee(name, id, 0)
    {
        this->dept = dept;
        cout << ">>>>>ovverided Teacher constructor called::::" << endl;
    }

    void printData()
    {
        Employee::printData();
        cout << "Department:  " << dept << endl;
    }
};

class Manager : public Employee
{
private:
};

int main()
{

    // Teacher t("Aftab Ali", "SCIT", 933);

    // int size = 8;
    // const Teacher *teacherArray = new Teacher[size];

    // Employee *const employeeArr = new Teacher[size];

    // t.printData();

    // cout << ">>>>|||Total Employee: " << Employee::getTotalEmployee() << endl;

    // Employee e(8);

    // const Employee *p2 = teacherArray;
    // p2 = employeeArr;

    // delete[] teacherArray;
    // delete[] employeeArr;


    return 0;
}