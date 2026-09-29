#include "Library.h"
#include <iostream>
#include <iomanip>
using namespace std;

Library::Library()
{
    numbersOfBooks = 0;
    book_prices = nullptr;
}

void Library::inputSize()
{
    cout << "Enter number of books: ";
    cin >> numbersOfBooks;

    if (numbersOfBooks <= 0)
    {
        cout << "Invalid number of books." << endl;
        numbersOfBooks = 0;
        book_prices = nullptr;
        return;
    }

    book_prices = new double[numbersOfBooks];
}

void Library::inputPrices()
{
    if (numbersOfBooks <= 0 || book_prices == nullptr)
    {
        return;
    }

    cout << "Enter prices of the books:" << endl;
    for (int i = 0; i < numbersOfBooks; i++)
    {
        cout << "Book " << (i + 1) << ": ";
        cin >> book_prices[i];
    }
}

void Library::display()
{
    if (numbersOfBooks <= 0 || book_prices == nullptr)
    {
        return;
    }

    double sum = 0.0;
    cout << "Book Prices:" << endl;
    for (int i = 0; i < numbersOfBooks; i++)
    {
        cout << "Book " << (i + 1) << ": " << book_prices[i] << endl;
        sum += book_prices[i];
    }
    cout << "Average Price: " << fixed << setprecision(2) << (sum / numbersOfBooks) << endl;
}


Library::~Library()
{
    delete[] book_prices;
    book_prices = nullptr;
}