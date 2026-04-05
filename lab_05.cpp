#include <iostream>
using namespace std;

class Employee
{
private:
    string emFirstName;
    string emLastName;

public:
    Employee();
    Employee(string emFName, string emLName);

    void setEmName(string fName, string lName);
    string getFirstName();
    string getLastName();
    void print();
};

Employee::Employee()
{
    emFirstName = "";
    emLastName = "";
}

Employee::Employee(string emFName, string emLName)
{
    emFirstName = emFName;
    emLastName = emLName;
}

void Employee::setEmName(string fName, string lName)
{
    emFirstName = fName;
    emLastName = lName;
}


string Employee::getFirstName()
{
    return emFirstName;
}

string Employee::getLastName()
{
    return emLastName;
}

void Employee::print()  
{
    cout << "First Name: " << emFirstName << endl;
    cout << endl;
    cout << "Last Name: " << emLastName << endl;
}

class partTimeEmployee : public Employee
{
private:
    float payRate;
    int hoursWorked;

public:
    partTimeEmployee()
    {
        payRate = 0;
        hoursWorked = 0;
    }

    partTimeEmployee(string fName, string lName, float rate, int hours) : Employee(fName, lName)
    {
        payRate = rate;
        hoursWorked = hours;
    }

    void set(string fName, string lName, float rate, int hours)
    {
        setEmName(fName, lName);
        payRate = rate;
        hoursWorked = hours;
    }

    int gethoursworked()
    {
        return hoursWorked;
    }

    void print()
    {
        Employee::print();
        cout << "Pay Rate: " << payRate << endl;
        cout << "Hours Worked: " << hoursWorked << endl;
    }

    float calculatePay()
    {
        return payRate * hoursWorked;
    }
};

class fullTimeEmployee : public Employee
{
private:
    float basicSalary;
    float houseRent;
    float taxRate;

public:
    fullTimeEmployee()
    {
        basicSalary = 0;
        houseRent = 0;
        taxRate = 0;
    }

    fullTimeEmployee(string fName, string lName, float salary, float rent, float tax) : Employee(fName, lName)
    {
        basicSalary = salary;
        houseRent = rent;
        taxRate = tax;
    }

    void set(string fName, string lName, float salary, float rent, float tax)
    {
        setEmName(fName, lName);
        basicSalary = salary;
        houseRent = rent;
        taxRate = tax;
    }

    void setTax(float tax)
    {
        taxRate = tax;
    }

    float getbasicsalary()
    {
        return basicSalary;
    }

    void print()
    {
        Employee::print();
        cout << "Basic salary: " << basicSalary << endl;
        cout << "House rent: " << houseRent << endl;
        cout << "Tax rate: " << taxRate << endl;
    }

    float calculateTax()
    {
        return basicSalary * taxRate;
    }

    float calculateSalary()
    {
        return (basicSalary + houseRent) - calculateTax();
    }
};

int main()
{

    cout << "............Printed All Employee details.........." << endl;

    Employee emp("Javeria", "Hussain");
    cout << "....Employee details are....:" << endl;
    emp.print();

    partTimeEmployee pTimeEmp1("Meerub", "Raza", 999, 5);
    cout << "....Part time employee details are....:" << endl;
    pTimeEmp1.print();

    cout << "Pay: " << pTimeEmp1.calculatePay() << endl;
    cout << "First Name of part time employee : " << pTimeEmp1.getFirstName() << endl;
    cout << "Hours Worked part time employee : " << pTimeEmp1.gethoursworked() << endl;

    fullTimeEmployee fTimeEmp1("Dua", "Fatima", 77500, 8550, 0.3);
    cout << "....Full time employee details are....:" << endl;
    fTimeEmp1.print();

    cout << "Salary: " << fTimeEmp1.calculateSalary() << endl;
    cout << "last Name of full time employee : " << fTimeEmp1.getLastName() << endl;
    cout << "basic salary of full time employee: " << fTimeEmp1.getbasicsalary() << endl;

    cout << "....Applied Tax Rate....." << endl;
    fTimeEmp1.setTax(0.2);

    cout << "New Salary full time employee: " << fTimeEmp1.calculateSalary() << endl;
    cout << "LAst Name of full time employee : " << fTimeEmp1.getLastName() << endl;
    cout << "basic Salary of full time employee : " << fTimeEmp1.getbasicsalary() << endl;

    cout << endl;
    cout << "............end........." << endl;

    return 0;
}