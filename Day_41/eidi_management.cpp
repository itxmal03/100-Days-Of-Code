#include <iostream>
using namespace std;

class StudentEidi
{

private:
    string studentName;
    int studentAge;
    int numberOfRelatives;
    double eidiReceived;

    static double totalEidi;
    static int studentCount;

public:
    StudentEidi()
    {
        this->studentName = "";
        this->studentAge = 0;
        this->numberOfRelatives = 0;
        this->eidiReceived = 0;
        studentCount++;
    }

    void setData(string name, int age, int relatives, double eidi)
    {
        studentName = name;
        studentAge = age;
        numberOfRelatives = relatives;
        eidiReceived = eidi;
        totalEidi += eidi;
        
    }

    string getStudentName()
    {
        return studentName;
    }

    int getStudentAge()
    {
        return studentAge;
    }

    int getStudentRelatives()
    {
        return numberOfRelatives;
    }

    double getStudentEidi()
    {
        return eidiReceived;
    }

    void displayStudentDetails()
    {
        cout << "__________ Student Details __________\n";
        cout << "Student Name_: " << studentName << endl;
        cout << "Student Age_: " << studentAge << endl;
        cout << "Number of Relatives_: " << numberOfRelatives << endl;
        cout << "Eidi Received_: " << eidiReceived << " Rupees" << endl;
        cout << endl;
    }

    static double getTotalEidi()
    {
        return totalEidi;
    }

    static int getStudentCount()
    {
        return studentCount;
    }

    static void highest_lowest(StudentEidi studentsArry[], int size)
    {
        StudentEidi maxEidi = studentsArry[0];

        for (int i = 1; i < size; i++)
        {
            int temp = i;
            while (temp > 0 && studentsArry[temp].getStudentEidi() < studentsArry[temp - 1].getStudentEidi())
            {
                StudentEidi tempStudent = studentsArry[temp];
                studentsArry[temp] = studentsArry[temp - 1];
                studentsArry[temp - 1] = tempStudent;
                temp--;
            }
        }
        cout << ">>> Highest Eidi Received By_: " << studentsArry[size - 1].getStudentName() << "---" << studentsArry[size - 1].getStudentEidi() << " Rupees\n";
    }
};

double StudentEidi::totalEidi = 0;
int StudentEidi::studentCount = 0;

void inputData(StudentEidi studentsArray[], int size)
{
    string name;
    int age, eidi, num;
    cout << "\n_____Input Students Details_____\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Student " << (i + 1) << "'s Name :_ ";
        getline(cin, name);
        cout << "Enter Student " << (i + 1) << "'s Age :_ ";
        cin >> age;
        cout << "Enter Student " << (i + 1) << "'s number of relatives who gave eidi:_ ";
        cin >> num;
        cout << "Enter Student " << (i + 1) << "'s total eidi received:_ ";
        cin >> eidi;
        studentsArray[i].setData(name, age, num, eidi);
        cin.ignore();
    }
}

void outputData(StudentEidi studentsArray[], int size)
{

    cout << "\n_____All Students Details_____\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Student " << (i + 1) << "'s Name :_ " << studentsArray[i].getStudentName() << endl;
        cout << "Student " << (i + 1) << "'s Age :_ " << studentsArray[i].getStudentAge() << endl;
        cout << "Student " << (i + 1) << " recieved eidi by:_" << studentsArray[i].getStudentRelatives() << " relatives." << endl;
        cout << "Student " << (i + 1) << "'s total eidi received:_ " << studentsArray[i].getStudentEidi() << endl;
    }
}

int main()
{
    StudentEidi studentsArr[3];
    inputData(studentsArr, 3);
    outputData(studentsArr, 3);

    cout << endl;
    cout << "|||STATS________: Total Eidi_: " << StudentEidi::getTotalEidi() << "  Total Students_: " << StudentEidi::getStudentCount() << endl;

    cout << endl;

    StudentEidi::highest_lowest(studentsArr, 3);

    return 0;
}