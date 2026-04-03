#include <iostream>
using namespace std;

class Employee
{
private:
    string firstName;
    string lastName;

public:
    Employee();
    Employee(string first, string last);
    void setData(string first, string last);
    string getfirstname();
    string getlastname();
    void printData();
};

Employee::Employee()
{
    this->firstName = "";
    this->lastName = "";
}

Employee::Employee(string first, string last)
{
    this->firstName = first;
    this->lastName = last;
}

void Employee::setData(string first, string last)
{
    firstName = first;
    lastName = last;
}

string Employee::getfirstname()
{
    return firstName;
}

string Employee::getlastname()
{
    return lastName;
}

void Employee::printData()
{
    cout << "First Name of Employee: " << firstName << endl;
    cout << "Last Name of Employee: " << lastName << endl;
}

class PartTimeEmployee : public Employee
{
private:
    double employeePayRate;
    double hoursWorked;

public:
    PartTimeEmployee();
    PartTimeEmployee(string first, string last, double rate, double hours);
    void setData(string first, string last, double rate, double hours);
    double gethoursworked();
    double calculateTotalPay();
    void printData();
};


PartTimeEmployee::PartTimeEmployee() : Employee()
{
    this->employeePayRate = 0;
    this->hoursWorked = 0;
}

PartTimeEmployee::PartTimeEmployee(string first, string last, double rate, double hours) : Employee(first, last)
{
    this->employeePayRate = rate;
    this->hoursWorked = hours;
}

void PartTimeEmployee::setData(string first, string last, double rate, double hours)
{
    Employee::setData(first, last);
    employeePayRate = rate;
    hoursWorked = hours;
}

double PartTimeEmployee::gethoursworked()
{
    return hoursWorked;
}

double PartTimeEmployee::calculateTotalPay()
{
    return (employeePayRate * hoursWorked);
}

void PartTimeEmployee::printData()
{
    Employee::printData();
    cout << "Pay Rate: " << employeePayRate << endl;
    cout << "Hours Worked: " << hoursWorked << endl;
}

class FullTimeEmployee : public Employee
{
private:
    double basicSalary;
    double houseRent;
    double taxRate;

public:
    FullTimeEmployee();
    FullTimeEmployee(string first, string last, double salary, double rent, double tax);
    void setData(string first, string last, double salary, double rent, double tax);
    void setTaxRate(double tax);
    double getBasicSalary();
    double calculateTax();
    double calculateSalary();
    void printData();
};

FullTimeEmployee::FullTimeEmployee() : Employee()
{
    basicSalary = 0;
    houseRent = 0;
    taxRate = 0;
}

FullTimeEmployee::FullTimeEmployee(string first, string last, double salary, double rent, double tax) : Employee(first, last)
{
    basicSalary = salary;
    houseRent = rent;
    taxRate = tax;
}

void FullTimeEmployee::setData(string first, string last, double salary, double rent, double tax)
{
    Employee::setData(first, last);
    basicSalary = salary;
    houseRent = rent;
    taxRate = tax;
}

void FullTimeEmployee::setTaxRate(double tax)
{
    taxRate = tax;
}

double FullTimeEmployee::getBasicSalary()
{
    return basicSalary;
}

double FullTimeEmployee::calculateTax()
{
    return (basicSalary * taxRate);
}

double FullTimeEmployee::calculateSalary()
{
    return (basicSalary + houseRent - calculateTax());
}

void FullTimeEmployee::printData()
{
    Employee::printData();
    cout << "Basic Salary of Employee: " << basicSalary << endl;
    cout << "House Rent of Employee: " << houseRent << endl;
    cout << "Tax Rate of Employee: " << taxRate << endl;
}

int main()
{

    Employee employee1("Muhammad", "Aftab");
    cout << "\n|||>>>Employee________:\n";
    employee1.printData();

    PartTimeEmployee partTimeEmployee1("Muhammad", "Ali", 1000, 12);
    cout << "\n|||>>>Part Time Employee________:\n";
    partTimeEmployee1.printData();

    cout << "Calculated Pay: " << partTimeEmployee1.calculateTotalPay() << endl;
    cout << "Name: " << partTimeEmployee1.getfirstname() + " " + partTimeEmployee1.getlastname() << endl;
    cout << "Hours: " << partTimeEmployee1.gethoursworked() << endl;

    FullTimeEmployee fullTimeEmployee1("Muhammad", "Afzal", 50000, 10000, 0.5);
    cout << "\n|||>>>Full Time Employee________:\n";
    fullTimeEmployee1.printData();

    cout << "Calculated Salary: " << fullTimeEmployee1.calculateSalary() << endl;
    cout << "Basic Salary: " << fullTimeEmployee1.getBasicSalary() << endl;

    fullTimeEmployee1.setTaxRate(0.2);

    cout << "\n|||>>>After applying Tax Rate________:\n";
    cout << "New Salary: " << fullTimeEmployee1.calculateSalary() << endl;
    cout << "Last Name: " << fullTimeEmployee1.getlastname() << endl;
    cout << "Basic Salary: " << fullTimeEmployee1.getBasicSalary() << endl;

    return 0;
}