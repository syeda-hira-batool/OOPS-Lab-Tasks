#include <iostream>
using namespace std;

class BalanceException {
	public:
	    string message;
	    double balance;
	
	    BalanceException(string msg, double bal) {
	        message = msg;
	        balance = bal;
	    }
};

int main() {
    double balance = 5000;
    double withdraw;

    try {
        cout << "Enter amount to withdraw: ";
        cin >> withdraw;

        if (withdraw > balance) {
            throw BalanceException("Insufficient balance!", balance);
        }

        balance = balance - withdraw;
        cout << "Withdrawal successful, Remaining balance: " << balance << endl;
    }
    catch (BalanceException e) {
        cout << "Error: " << e.message << endl;
        cout << "Available balance: " << e.balance << endl;
    }

    return 0;
}
