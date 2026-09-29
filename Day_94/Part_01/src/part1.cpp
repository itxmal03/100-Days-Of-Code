#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of books: " << endl;
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of books." << endl;
        return 0;
    }

    double *book_prices = new double[n];

    cout << "Enter prices of the books:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Book " << (i + 1) << ": ";
        cin >> book_prices[i];
    }

    double sum = 0.0;
    cout << "Book Prices:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Book " << (i + 1) << ": " << book_prices[i] << endl;
        sum += book_prices[i];
    }

    cout << "Average Price: " << fixed << setprecision(2) << (sum / n) << endl;

    delete[] book_prices;
    book_prices = nullptr;

    return 0;
}