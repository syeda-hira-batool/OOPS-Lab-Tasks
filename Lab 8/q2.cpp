#include <iostream>
#include <string>
using namespace std;

class Account
{
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    Account(string a, string h, double b)
    {
        accountNumber = a;
        accountHolder = h;
        balance = b;
    }

    Account operator+(const Account &other)
    {
        double totalBalance = this->balance + other.balance;

        return Account("000", "Combined Account", totalBalance);
    }

    Account &operator-=(double amount)
    {
        if (balance >= amount)
        {
            balance -= amount;
        }
        else
        {
            cout << "Insufficient funds in " << accountHolder << "'s account!" << endl;
        }
        return *this;
    }

    bool operator>(const Account &other)
    {
        return this->balance > other.balance;
    }

    friend ostream &operator<<(ostream &out, const Account &acc)
    {
        cout << "Account Number: " << acc.accountNumber
             << " Holder: " << acc.accountHolder
             << " Balance: " << acc.balance;
        return out;
    }

    double getBalance() const
    {
        return balance;
    }

    string getHolder() const
    {
        return accountHolder;
    }
};

int main()
{

    Account acc1("101", "Sunghoon Park", 6767);
    Account acc2("102", "Lee Heeseung", 6760);

    Account total = acc1 + acc2;
    cout << "Total Balance: " << total.getBalance() << endl;

    acc1 -= 2000;
    acc2 = Account("102", "Lee Heeseung", acc2.getBalance() + 2000);

    cout << "After Transfer:" << endl;
    cout << acc1.getHolder() << "'s New Balance: " << acc1.getBalance() << endl;
    cout << acc2.getHolder() << "'s New Balance: " << acc2.getBalance() << endl;

    if (acc1 > acc2)
    {
        cout << acc1.getHolder() << " has more balance than " << acc2.getHolder() << endl;
    }
    else
    {
        cout << acc1.getHolder() << " has less balance than " << acc2.getHolder() << endl;
    }

    cout << "Final Account Details:" << endl;
    cout << acc1 << endl;
    cout << acc2 << endl;

    return 0;
}
