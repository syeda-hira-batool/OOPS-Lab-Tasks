#include <iostream>
#include <string>
using namespace std;

class Account
{

private:
    long long AccountNumber;
    string AccountHolderName;
    long long CurrentBalance;

public:
    Account()
    {
        AccountNumber = 0;
        AccountHolderName = "Unknown";
        CurrentBalance = 0;
    }

    void set(long long AN, long long CB, string name)
    {
        AccountNumber = AN;
        AccountHolderName = name;
        CurrentBalance = CB;
    }

    void Deposit()
    {
        long long amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Error! Deposit must be positive.\n";
            return;
        }

        CurrentBalance += amount;
        cout << "Deposit successful\nCurrent Balance: " << CurrentBalance << endl;
    }

    void Withdraw()
    {
        long long amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if (amount <= 0)
        {
            cout << "Error! Withdrawal amount must be positive.\n";
            return;
        }

        if (amount > CurrentBalance)
        {
            cout << "Error! Insufficient balance.\n";
            return;
        }

        CurrentBalance -= amount;
        cout << "Withdrawal successful\nCurrent Balance: " << CurrentBalance << endl;
    }

    void CheckCurrentBalance()
    {
        cout << "Current Balance: " << CurrentBalance << endl;
    }

    void display()
    {
        cout << "\nAccount Holder Name: " << AccountHolderName << endl;
        cout << "Account Number: " << AccountNumber << endl;
        cout << "Final Balance: " << CurrentBalance << endl;
        cout << "=====================================\n";
    }
};

int main()
{

    Account A1, A2;

    A1.set(1021110002, 50000, "Ali");
    A2.set(1203436345, 75000, "Ahmed");

    A1.CheckCurrentBalance();
    A1.Deposit();
    A1.Withdraw();

    A2.CheckCurrentBalance();
    A2.Deposit();
    A2.Withdraw();

    A1.display();
    A2.display();

    return 0;
}
