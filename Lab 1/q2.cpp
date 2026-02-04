#include <iostream>
#include <string>
using namespace std;

struct Book
{
    int ID;
    string Booktitle;
    string AuthorName;
    float Price;
};

int main()
{

    Book b1, b2, b3;

    cout << "Enter the Book ID for book 1: ";
    cin >> b1.ID;
    cin.ignore();

    cout << "Enter the Book Author Name for book 1: ";
    getline(cin, b1.AuthorName);

    cout << "Enter the Book Title for book 1: ";
    getline(cin, b1.Booktitle);

    cout << "Enter the Book price for book 1: ";
    cin >> b1.Price;

    cout << "\nEnter the Book ID for book 2: ";
    cin >> b2.ID;
    cin.ignore();

    cout << "Enter the Book Author Name for book 2: ";
    getline(cin, b2.AuthorName);

    cout << "Enter the Book Title for book 2: ";
    getline(cin, b2.Booktitle);

    cout << "Enter the Book price for book 2: ";
    cin >> b2.Price;

    cout << "\nEnter the Book ID for book 3: ";
    cin >> b3.ID;
    cin.ignore();

    cout << "Enter the Book Author Name for book 3: ";
    getline(cin, b3.AuthorName);

    cout << "Enter the Book Title for book 3: ";
    getline(cin, b3.Booktitle);

    cout << "Enter the Book price for book 3: ";
    cin >> b3.Price;

    cout << "\nDisplaying info:\n";
    cout << "\nBook 1:";
    cout << "\nID: " << b1.ID;
    cout << "\nAuthor: " << b1.AuthorName;
    cout << "\nTitle: " << b1.Booktitle;
    cout << "\nPrice: " << b1.Price << endl;
    cout << "\nBook 2:";
    cout << "\nID: " << b2.ID;
    cout << "\nAuthor: " << b2.AuthorName;
    cout << "\nTitle: " << b2.Booktitle;
    cout << "\nPrice: " << b2.Price << endl;
    cout << "\nBook 3:";
    cout << "\nID: " << b3.ID;
    cout << "\nAuthor: " << b3.AuthorName;
    cout << "\nTitle: " << b3.Booktitle;
    cout << "\nPrice: " << b3.Price << endl;

    float total = b1.Price + b2.Price + b3.Price;
    cout << "\nTotal Price is: " << total << endl;

    return 0;
}