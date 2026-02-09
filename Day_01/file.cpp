#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    int direction;
    float speed1, speed2, distance, relativeSpeed;
    cout << "Enter speed of 1st person m/s: ";
    cin >> speed1;
    cout << "Enter speed of 2nd person m/s: ";
    cin >> speed2;
    cout << "Enter distance btw persons in meters: ";
    cin >> distance;
    do
    {
        cout << "Enter 1 if they are moving towards each other & 2 if moving apart: ";
        cin >> direction;
        if (direction != 1 && direction != 2)
        {
            cout << "Invalid input";
            continue;
        }
    } while (direction != 1 && direction != 2);

    if (direction == 1)
    {
        relativeSpeed = speed1 + speed2;
        double time = distance / relativeSpeed;
        cout << fixed << setprecision(1) << "They will meet after " << time << " seconds" << endl;
    }
    else
    {
        relativeSpeed = fabs(speed1 - speed2);
        if (relativeSpeed == 0)
        {
            cout << "They will never meet!";
        }
        else
        {
            double time = distance / relativeSpeed;
            cout << fixed << setprecision(1) << "They will meet after " << time << " seconds" << endl;
        }
    }

    return 0;
}