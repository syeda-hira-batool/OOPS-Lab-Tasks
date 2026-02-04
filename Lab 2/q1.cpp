#include <iostream>
#include <string>
using namespace std;

class Book
{
private:
    string isbn;
    bool avail;

public:
    string title;
    string author;

    Book()
    {
        avail = true;
    }

    void setBook(string t, string a, string i)
    {
        title = t;
        author = a;
        isbn = i;
        avail = true;
    }

    string getISBN()
    {
        return isbn;
    }

    bool Avail()
    {
        return avail;
    }

    void borrow()
    {
        avail = false;
    }

    void returnb()
    {
        avail = true;
    }

    void display()
    {
        cout << "Book Title: " << title << endl;
        cout << "Book Author: " << author << endl;
        cout << "Book ISBN: " << isbn << endl;
        if (avail == true)
        {
            cout << "Book Status: Available" << endl;
        }
        else
        {
            cout << "Book Status: Borrowed" << endl;
        }
        cout << "===================================" << endl;
    }
};

int main()
{

    int n;
    cout << "Enter number of books: ";
    cin >> n;

    Book books[50]; // assuming there are 50 books in total

    for (int i = 0; i < n; i++)
    {
        string t, a, isbn;

        cout << "\nEnter details for Book " << i + 1 << endl;

        cin.ignore(); // clear leftover newline once

        cout << "Book Title: ";
        getline(cin, t);

        cout << "Book Author: ";
        getline(cin, a);

        cout << "Book ISBN: ";
        cin >> isbn;

        books[i].setBook(t, a, isbn);
    }

    int choice;
    // displaying the menu for user interference
    do
    {
        cout << "\n===== Library Menu =====" << endl;
        cout << "1. Display all books" << endl;
        cout << "2. Borrow book" << endl;
        cout << "3. Return book" << endl;
        cout << "4. Search book" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
        {
            for (int i = 0; i < n; i++)
            {
                books[i].display();
            }
        }

        else if (choice == 2)
        {
            string searchISBN;
            cout << "Enter ISBN to borrow: ";
            cin >> searchISBN;

            bool found = false;
            for (int i = 0; i < n; i++)
            {
                if (books[i].getISBN() == searchISBN)
                {
                    found = true;
                    if (books[i].Avail())
                    {
                        books[i].borrow();
                        cout << "Book borrowed successfully." << endl;
                    }
                    else
                    {
                        cout << "Book is already borrowed." << endl;
                    }
                    break;
                }
            }
            if (!found)
                cout << "Book not found." << endl;
        }

        else if (choice == 3)
        {
            string searchISBN;
            cout << "Enter ISBN to return: ";
            cin >> searchISBN;

            bool found = false;
            for (int i = 0; i < n; i++)
            {
                if (books[i].getISBN() == searchISBN)
                {
                    found = true;
                    books[i].returnb();
                    cout << "Book returned successfully." << endl;
                    break;
                }
            }
            if (!found)
                cout << "Book not found." << endl;
        }

        else if (choice == 4)
        {
            string searchISBN;
            cout << "Enter ISBN to search: ";
            cin >> searchISBN;

            bool found = false;
            for (int i = 0; i < n; i++)
            {
                if (books[i].getISBN() == searchISBN)
                {
                    books[i].display();
                    found = true;
                    break;
                }
            }
            if (!found)
                cout << "Book not found." << endl;
        }

    } while (choice != 0);

    return 0;
}
