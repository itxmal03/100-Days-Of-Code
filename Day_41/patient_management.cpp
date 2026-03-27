#include <iostream>
using namespace std;

class Patient
{
private:
    string fName;
    string midName;
    string plast_Name;
    string address;
    string city;
    string state;
    int zipCode;
    string phoneNumber;
    string emergencyName;
    string emergencyContact;

public:
    Patient()
    {
        this->fName = "";
        this->midName = "";
        this->plast_Name = "";
        this->address = "";
        this->city = "";
        this->state = "";
        this->zipCode = 0;
        this->phoneNumber = "";
        this->emergencyContact = "";
        this->emergencyName = "";
    }

    void setData(string fName, string midName, string lstName, string pAddress, string pCity, string pState, int zCode, string pNum, string eName, string eNum)
    {
        this->fName = fName;
        this->midName = midName;
        this->plast_Name = lstName;
        this->address = pAddress;
        this->city = pCity;
        this->state = pState;
        this->zipCode = zCode;
        this->phoneNumber = pNum;
        this->emergencyContact = eNum;
        this->emergencyName = eName;
    }

    string getFullName()
    {
        return fName + " " + midName + " " + plast_Name;
    }

    string getAddress()
    {
        return address + ", " + city + ", " + state;
    }

    int getZip()
    {
        return zipCode;
    }

    string getPhone()
    {
        return phoneNumber;
    }

    string getEmergencyDetails()
    {
        return emergencyName + " (--ph# " + emergencyContact + ")";
    }

    void displayPatientDetails()
    {
        cout << endl
             << endl;
        cout << "__________ Patient Details __________\n";
        cout << "Patient Name_: " << getFullName() << endl;
        cout << "Complete Address_: " << getAddress() << endl;
        cout << "ZIP Code_: " << getZip() << endl;
        cout << "Patient Phone Number_: " << getPhone() << endl;
        cout << "Emergency Contact Details_: " << getEmergencyDetails() << endl;
        cout << endl;
    }
};

class Procedure
{
private:
    string procedureName;
    string dateOfProcedure;
    string practitioner;
    double procedureCharges;
    static double totalCharges;
    static int totalProcedures;

public:
    Procedure()
    {
        procedureName = "";
        dateOfProcedure = "";
        practitioner = "";
        procedureCharges = 0;
    }

    void setData(string name, string date, string prac, double charges)
    {
        procedureName = name;
        dateOfProcedure = date;
        practitioner = prac;
        procedureCharges = charges;
        totalCharges += charges;
        totalProcedures++;
    }

    string getName()
    {
        return procedureName;
    }

    string getDate()
    {
        return dateOfProcedure;
    }

    string getPractitioner()
    {
        return practitioner;
    }

    double getCharges()
    {
        return procedureCharges;
    }

    void displayProcedureDetails()
    {
        cout << "Name of Procedure_: " << procedureName << endl;
        cout << "Date When Held_: " << dateOfProcedure << endl;
        cout << "Doctor Name_: " << practitioner << endl;
        cout << "Charges of Procedure_: " << procedureCharges << "Rupees" << endl;
        cout << endl;
    }

    static double getTotalCharges()
    {
        return totalCharges;
    }

    static int getTotalProcedures()
    {
        return totalProcedures;
    }
};

double Procedure::totalCharges = 0;
int Procedure::totalProcedures = 0;

int main()
{
    Patient patient1;

    patient1.setData("Muhammad", "Aftab", "Liaqat", "Street 1", "Chishtian", "Punjab", 3200, "03246923838", "Ali", "03111234567");

    Procedure patient1_procedure, patient2_procedure, patient3_procedure;

    patient1_procedure.setData("Eye Sight Test", "Today", "Dr. Ishfaq Ahmed", 2500.00);
    patient2_procedure.setData("X-ray Test", "10/03/2026", "Dr. Jawaad Ali", 5200.00);
    patient3_procedure.setData("Blood Test", "09/03/2026", "Dr. Alyaar", 2400.00);
    patient1.displayPatientDetails();

    cout << "__________ Details of all held Procedures __________\n";
    patient1_procedure.displayProcedureDetails();
    patient2_procedure.displayProcedureDetails();
    patient3_procedure.displayProcedureDetails();

    cout << "|||STATS________: Total Charges_: " << Procedure::getTotalCharges() << "  Total Procedures_: " << Procedure::getTotalProcedures() << endl;

    return 0;
}