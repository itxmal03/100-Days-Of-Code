#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class Publication
{
private:
    string title;
    float price;
    int sales[3];

public:
    Publication(string t = "", float p = 0.0, int s0 = 0, int s1 = 0, int s2 = 0);
    string getTitle() const;
    float getPrice() const;
    int getSales(int i) const;
    void setPublicationTitle(string t);
    void setPrice(float p);
    void setMonthlySales(int s0, int s1, int s2);
    virtual void print() const;
    int maxSales() const;
    virtual void updatePrice();
    virtual void input();
    int sizeOfFile(string fileName);
};

Publication::Publication(string t, float p, int s0, int s1, int s2)
{
    this->title = t;
    this->price = p;
    this->sales[0] = s0;
    this->sales[1] = s1;
    this->sales[2] = s2;
}
string Publication::getTitle() const
{
    return title;
}
float Publication::getPrice() const
{
    return price;
}
int Publication::getSales(int i) const
{
    return sales[i];
}
void Publication::setPublicationTitle(string t)
{
    title = t;
}
void Publication::setPrice(float p)
{
    price = p;
}
void Publication::setMonthlySales(int s0, int s1, int s2)
{
    sales[0] = s0;
    sales[1] = s1;
    sales[2] = s2;
}
void Publication::print() const
{
    cout << ">>>Title  : " << title << endl;
    cout << ">>>Price  : " << price << endl;
    cout << ">>>Sales  : Month1=" << sales[0] << "  Month2=" << sales[1] << "  Month3=" << sales[2] << endl;
}
int Publication::maxSales() const
{
    int max = sales[0];
    if (sales[1] > max)
    {
        max = sales[1];
    }
    if (sales[2] > max)
    {
        max = sales[2];
    }
    return max;
}
void Publication::updatePrice()
{
    if (maxSales() > 10000)
    {
        price += 100;
        cout << ">>> Price updated! New price: Rs " << price << endl;
    }
    else
    {
        cout << ">>> No price update needed!!!!!!!" << endl;
    }
}
void Publication::input()
{
    cout << "Enter title: ";
    getline(cin, title);
    cout << "Enter price: ";
    cin >> price;
    cout << "Enter sales for last 3 months: ";
    cin >> sales[0] >> sales[1] >> sales[2];
    cin.ignore();
}

int Publication::sizeOfFile(string fileName)
{
    ifstream file(fileName);
    int totalLines = 0;

    if (!file.is_open())
    {
        cerr << "File opening error" << endl;
        return -1;
    }

    string line;
    while (getline(file, line))
    {
        if (!line.empty())
            totalLines++;
    }

    file.close();

    return totalLines;
}

class Book : public Publication
{
private:
    string author;
    int pageCount;

public:
    Book(string t = "", float p = 0.0, int s0 = 0, int s1 = 0, int s2 = 0, string a = "", int pg = 0);
    string getAuthor() const;
    int getPageCount() const;
    void setAuthor(string a);
    void setPageCount(int pg);
    void print() const override;
    bool searchByAuthor(const string &name) const;
    void updatePrice() override;
    void input() override;
    void readFromFile(ifstream &file);
};

Book::Book(string t, float p, int s0, int s1, int s2, string a, int pg) : Publication(t, p, s0, s1, s2)
{
    this->author = a;
    this->pageCount = pg;
}

string Book::getAuthor() const
{
    return author;
}
int Book::getPageCount() const
{
    return pageCount;
}
void Book::setAuthor(string a)
{
    author = a;
}
void Book::setPageCount(int pg)
{
    pageCount = pg;
}
void Book::print() const
{
    Publication::print();
    cout << ">>> Author : " << author << endl;
    cout << ">>> Pages  : " << pageCount << endl;
}
bool Book::searchByAuthor(const string &name) const
{
    return author == name;
}
void Book::updatePrice()
{
    if (maxSales() > 5000 && pageCount > 300)
    {
        float newPrice = getPrice() + 150;
        setPrice(newPrice);
        cout << "Book price updated! New price: Rs " << getPrice() << endl;
    }
    else
    {
        cout << ">>>No price update needed for this book!!!!" << endl;
    }
}
void Book::input()
{
    Publication::input();
    cout << "Enter author: ";
    getline(cin, author);
    cout << "Enter page count: ";
    cin >> pageCount;
    cin.ignore();
}
void Book::readFromFile(ifstream &file)
{
    string line;
    while (getline(file, line))
    {
        if (!line.empty())
            break;
    }

    istringstream ss(line);
    string title, author;
    float price;
    int sale1, sale2, sale3, pages;

    ss >> title >> price >> sale1 >> sale2 >> sale3 >> author >> pages;

    setPublicationTitle(title);
    setPrice(price);
    setMonthlySales(sale1, sale2, sale3);
    setAuthor(author);
    setPageCount(pages);
}

class DVD : public Publication
{
private:
    int playingTime;

public:
    DVD(string t = "", float p = 0.0, int s0 = 0, int s1 = 0, int s2 = 0, int pt = 0);
    int getPlayingTime() const;
    void setPlayingTime(int pt);
    void print() const override;
    void updatePrice() override;
    void input() override;
    void readFromFile(ifstream &file);
};

DVD::DVD(string t, float p, int s0, int s1, int s2, int pt) : Publication(t, p, s0, s1, s2)
{
    playingTime = pt;
}

int DVD::getPlayingTime() const
{
    return playingTime;
}
void DVD::setPlayingTime(int pt)
{
    playingTime = pt;
}
void DVD::print() const
{
    Publication::print();
    cout << "Playing Time: " << playingTime << " minutes" << endl;
}
void DVD::updatePrice()
{
    if (maxSales() > 10000 && playingTime < 20)
    {
        float newPrice = getPrice() + 180;
        setPrice(newPrice);
        cout << ">>>DVD price updated!!!! New price: Rs. " << getPrice() << endl;
    }
    else
    {
        cout << ">>>No price update needed for this DVD!!!!!" << endl;
    }
}
void DVD::input()
{
    Publication::input();
    cout << "Enter playing time: ";
    cin >> playingTime;
    cin.ignore();
}
void DVD::readFromFile(ifstream &file)
{
    string line;
    while (getline(file, line))
    {
        if (!line.empty())
            break;
    }

    istringstream ss(line);
    string title;
    float price;
    int sale1, sale2, sale3, playingTime;

    ss >> title >> price >> sale1 >> sale2 >> sale3 >> playingTime;

    setPublicationTitle(title);
    setPrice(price);
    setMonthlySales(sale1, sale2, sale3);
    setPlayingTime(playingTime);
}

void separator()
{
    char c = '-';
    for (int i = 0; i < 32; i++)
        cout << c;
    cout << endl;
}

int main()
{
    separator();
    cout << ">>>>>>>>>>>BOOKS<<<<<<<<<<" << endl;
    separator();

    Publication tempBook;
    int bookCount = tempBook.sizeOfFile("Book.txt");

    Book *books = new Book[bookCount];

    ifstream bookFile("Book.txt");
    if (!bookFile.is_open())
    {
        cerr << "Error opening Book.txt" << endl;
        return 1;
    }

    for (int i = 0; i < bookCount; i++)
    {
        books[i].readFromFile(bookFile);
    }
    bookFile.close();

    cout << endl;
    separator();
    cout << ">>>>>>>>>>>List of All Books<<<<<<<<<<<<" << endl;
    separator();
    for (int i = 0; i < bookCount; i++)
    {
        cout << "Book " << (i + 1) << ":" << endl;
        books[i].print();
        separator();
    }

    string searchAuthor;
    cout << "\nEnter author name to search: ";
    getline(cin, searchAuthor);

    bool found = false;
    for (int i = 0; i < bookCount; i++)
    {
        if (books[i].searchByAuthor(searchAuthor))
        {
            cout << "Found! Book " << (i + 1) << " details:" << endl;
            books[i].print();
            found = true;
        }
    }
    if (!found)
    {
        cout << "No book found by author: " << searchAuthor << endl;
    }

    int maxSale = books[0].maxSales();
    int maxIdx = 0;
    for (int i = 1; i < bookCount; i++)
    {
        if (books[i].maxSales() > maxSale)
        {
            maxSale = books[i].maxSales();
            maxIdx = i;
        }
    }
    cout << "\nHighest selling book: \"" << books[maxIdx].getTitle() << "\" with max sales: " << maxSale << endl;

    separator();
    cout << "\n>>>>> Checking price updates for all books <<<<<<<<<" << endl;
    separator();
    for (int i = 0; i < bookCount; i++)
    {
        cout << "Book " << (i + 1) << " (" << books[i].getTitle() << "): ";
        books[i].updatePrice();
    }

    delete[] books;

    separator();
    cout << ">>>>>>>>>>DVDs<<<<<<<<<<" << endl;
    separator();

    Publication tempDvd;
    int dvdCount = tempDvd.sizeOfFile("DVD.txt");

    DVD *dvds = new DVD[dvdCount];

    ifstream dvdFile("DVD.txt");
    if (!dvdFile.is_open())
    {
        cerr << "Error opening Dvd.txt" << endl;
        return 1;
    }

    for (int i = 0; i < dvdCount; i++)
    {
        dvds[i].readFromFile(dvdFile);
    }
    dvdFile.close();

    cout << "\n\n>>>>>>>>>> List of All DVDs <<<<<<<<<<" << endl;
    for (int i = 0; i < dvdCount; i++)
    {
        cout << "\nDVD " << (i + 1) << ":" << endl;
        dvds[i].print();
        separator();
    }

    int maxDvdSale = dvds[0].maxSales();
    int maxDvdIdx = 0;
    for (int i = 1; i < dvdCount; i++)
    {
        if (dvds[i].maxSales() > maxDvdSale)
        {
            maxDvdSale = dvds[i].maxSales();
            maxDvdIdx = i;
        }
    }
    cout << "\nHighest selling DVD: \"" << dvds[maxDvdIdx].getTitle() << "\" with max sales: " << maxDvdSale << endl;

    separator();
    cout << "\n>>>>>>>>>>Checking price updates for all DVDs<<<<<<<<<<<<<" << endl;
    separator();
    for (int i = 0; i < dvdCount; i++)
    {
        cout << "DVD " << (i + 1) << " (" << dvds[i].getTitle() << "): ";
        dvds[i].updatePrice();
    }

    delete[] dvds;

    return 0;
}