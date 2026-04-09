#include <iostream>
using namespace std;

class MovieTicket
{
private:
    string movieName;
    float price;
    int seatNum;
    static double totalSales;

public:
    MovieTicket()
    {
    }
    MovieTicket(string name, float p, int num)
    {
        this->movieName = name;
        this->price = p;
        this->seatNum = num;
        totalSales += price;
    }
    void show()
    {
        cout << "Movie Name: " << this->movieName << endl;
        cout << "Price: " << this->price << endl;
        cout << "Seat Number: " << this->seatNum << endl;
    }
    static double getTotalSales()
    {
        return totalSales;
    }
};

double MovieTicket::totalSales = 0;

int main()
{
    int totalTickets;
    cin >> totalTickets;
    MovieTicket *ticketsArray = new MovieTicket[totalTickets];

    string movieName;
    float price;
    int seatNum;

    for (int i = 0; i < totalTickets; i++)
    {
        cin >> movieName;
        cin >> price;
        cin >> seatNum;
        ticketsArray[i] = MovieTicket(movieName, price, seatNum);
    }

    for (int i = 0; i < totalTickets; i++)
    {
        ticketsArray[i].show();
    }
    cout << "total sales: " << MovieTicket::getTotalSales() << endl;

    // no default construcor is needed if we will create array like this using parameterized constructor;
    // MovieTicket *ticketsArray = new MovieTicket[3]{
    //     MovieTicket("A", 100, 1),
    //     MovieTicket("B", 200, 2),
    //     MovieTicket("C", 300, 3)};

    delete[] ticketsArray;
    return 0;
}