#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

class Book
{
private:
    int bookID;
    string bookName;
    string authorName;
    bool bookAvailable;

public:
    Book()
    {
        this->bookID = 0;
        this->bookName = "";
        this->authorName = "";
        this->bookAvailable = false;
    }

    void returnBook(vector<Book> &booksVector)
    {
        int id;
        cout << "\n---Return Book---\n";
        cout << "Enter Id of book: ";
        cin >> id;

        for (Book &book : booksVector)
        {
            if (book.bookID == id && !book.bookAvailable)
            {
                book.bookAvailable = true;
                cout << "Book returned successfully!\n";
                return;
            }
        }
        cout << "This is book was not borrowed to anyone! Hence can't be returned.\n";
    }

    void searchBook(vector<Book> &booksVector)
    {
        string name;
        bool isFindWithId = false, isFindWithName = false;
        int searchChoice, id;
        cout << "\n---Search Book---\n";
        while (true)
        {
            cout << "Press 1 to search by Book ID and press 2 to search by Book name: ";
            cin >> searchChoice;
            if (searchChoice == 1 || searchChoice == 2)
                break;
            cout << "Invalid input. Try again.\n";
        }

        if (searchChoice == 1)
        {
            cout << "Enter book id: ";
            cin >> id;
        }
        else
        {

            cout << "Enter book name: ";
            cin >> name;
        }

        for (Book &book : booksVector)
        {
            if (searchChoice == 1)
            {
                if (book.bookID == id)
                {
                    isFindWithId = true;
                    cout << "Yes book with id: " << id << " exists!" << (book.bookAvailable ? " and it is available" : " but currently this is not available.");
                    break;
                }
            }
            else
            {
                if (book.bookName == name)
                {
                    isFindWithName = true;
                    cout << "Yes book with name: " << name << " exists!" << (book.bookAvailable ? " and it is available" : " but currently this is not available.");
                    break;
                }
            }
        }
        if (searchChoice == 1 && !isFindWithId)
            cout << "No book with this id exists!\n";
        else if (searchChoice == 2 && !isFindWithName)
            cout << "No book with this name exists!\n";
    }

    void displayDetails(vector<Book> &booksVector)
    {
        for (Book &b : booksVector)
        {
            cout << "Book ID: " << b.bookID << endl;
            cout << "Book name: " << b.bookName << endl;
            cout << "Book Author name: " << b.authorName << endl;
            cout << "Book current status: " << (b.bookAvailable ? "Available" : "Issued") << endl;
        }
    }

    void issueBook(vector<Book> &booksVector)
    {
        string borrower;
        int id;
        bool isFind = false;
        cout << "\n---Issue Book--- \n";
        cout << "Enter book ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter name of borrower: ";
        getline(cin, borrower);
        for (Book &b : booksVector)
        {
            if (b.bookID == id && b.bookAvailable)
            {
                isFind = true;
                b.bookAvailable = false;
                cout << "Book issued!!!\n";
                return;
            }
        }
        if (!isFind)
        {
            cout << "Book is unavailable currently !!!\n";
        }
    }

    void inputDetailsFromUser(vector<Book> &booksVector)
    {
        int totalBooks;
        while (true)
        {
            cout << "Enter total number of books: ";
            cin >> totalBooks;
            if (totalBooks > 0 && totalBooks <= 1000)
                break;
            cout << "Invalid number of books. Try again total number between 1 and 1000.\n";
        }

        int loopControl = 0;
        do
        {
            Book book;
            cout << "Enter details of book: " << (loopControl + 1) << endl;
            cout << "Enter ID of book: ";
            cin >> book.bookID;
            cin.ignore();
            cout << "Enter name of book: ";
            getline(cin, book.bookName);
            cout << "Enter author of book: ";
            getline(cin, book.authorName);
            cout << "Enter status of book if available , enter 1 and if not available enter 0: ";
            cin >> book.bookAvailable;
            booksVector.push_back(book);
            loopControl++;
        } while (loopControl < totalBooks);
    }

    void calculateAvailable(vector<Book> &booksVector)
    {
        int counter = 0;
        for (Book &b : booksVector)
        {
            if (b.bookAvailable)
            {
                counter++;
            }
        }
        cout << "Total available books: " << counter << endl;
    }
};

int main()
{
    vector<Book> booksVector;
    Book book;
    book.inputDetailsFromUser(booksVector);
    book.displayDetails(booksVector);
    book.searchBook(booksVector);
    book.issueBook(booksVector);
    book.returnBook(booksVector);
    book.calculateAvailable(booksVector);

    return 0;
}