#include <iostream>
using namespace std;

class Appliance
{
private:
    string applianceName;
    int appliancePower;
    bool applianceStatus;

public:
    Appliance(string name, int power)
    {
        this->applianceName = name;
        this->appliancePower = power;
        this->applianceStatus = false;
    }

    void turnOn()
    {
        applianceStatus = true;
    }
    void turnOff()
    {
        applianceStatus = false;
    }

    int getPower()
    {
        if (applianceStatus)
            return appliancePower;
        else
            return 0;
    }

    string getName()
    {
        return applianceName;
    }

    bool getStatus()
    {
        return applianceStatus;
    }

    void powerControl()
    {
        int control, magnitude;
        do
        {
            cout << "Press 1 to increase power and 2 to decrease power! : ";
            cin >> control;

            if (control != 1 && control != 2)
            {
                cout << "INVALID input !!! Please Enter 1 or 2 to adjust power\n";
            }
        } while (control != 1 && control != 2);

        if (control == 1)
        {
            cout << "Enter Magnitude to be increased: ";
            cin >> magnitude;
            appliancePower += magnitude;
        }
        else
        {
            cout << "Enter Magnitude to be decreased: ";
            cin >> magnitude;
            appliancePower -= magnitude;
        }
    }

    void displayStatus()
    {
        cout << "Appliance Name: " << applianceName << endl;
        cout << "Appliance Status: " << (applianceStatus ? "On" : "Off") << endl;
        cout << "Current power of appliance: " << appliancePower << endl;
    }
};

int displayTotalPower(Appliance &app1, Appliance &app2, Appliance &app3)
{
    return (app1.getPower() + app2.getPower() + app3.getPower());
}

int main()
{
    Appliance app1("Fan", 500);
    app1.turnOn();
    Appliance app2("Iron", 1000);
    app2.turnOff();
    Appliance app3("Washing Machine", 1500);
    app3.turnOn();

    app1.displayStatus();
    app2.displayStatus();
    app3.displayStatus();

    cout << "Total Power off all appliances : " << displayTotalPower(app1, app2, app3) << endl;

    char loopConrol;
    int appState;
    do
    {
        cout << "\nPress 1 to turn ON and press 2 to turn OFF " << app1.getName() << ": ";
        cin >> appState;
        (appState == 1 ? app1.turnOn() : app1.turnOff());
        cout << "Press 1 to turn ON and press 2 to turn OFF " << app2.getName() << ": ";
        cin >> appState;
        (appState == 1 ? app2.turnOn() : app2.turnOff());
        cout << "Press 1 to turn ON and press 2 to turn OFF " << app3.getName() << ": ";
        cin >> appState;
        (appState == 1 ? app3.turnOn() : app3.turnOff());

        cout << "\nPress 'e' to exit and to continue press any character!!!!: ";
        cin >> loopConrol;

    } while (loopConrol != 'e');

    cout << "\nTotal Power off all appliances after loop : " << displayTotalPower(app1, app2, app3) << endl;

    cout << "Update power of " << app1.getName() << endl;
    app1.powerControl();
    cout << "Update power of " << app2.getName() << endl;
    app2.powerControl();
    cout << "Update power of " << app3.getName() << endl;
    app3.powerControl();

    cout << "\nTotal Power off all appliances after updating power of all appliances : " << displayTotalPower(app1, app2, app3) << endl;

    return 0;
}