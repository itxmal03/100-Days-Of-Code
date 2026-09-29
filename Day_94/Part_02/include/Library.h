#ifndef LIBRARY_H
#define LIBRARY_H

class Library
{
private:
    int numbersOfBooks;
    double *book_prices;

public:
    Library();
    void inputSize();
    void inputPrices();
    void display();
    ~Library();
};

#endif