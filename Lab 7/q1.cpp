#include <iostream>
#include<string>
using namespace std;

class Bank {
public:
    virtual void calculateInterest(double balance) {
    	cout << "Standard Bank Interest: $0" << endl;
    }
    virtual ~Bank() {}
};

class SavingsAccount : public Bank {
public:
    void calculateInterest(double balance) override {
        double interest = balance * 0.05; 
        	cout << "Savings Account Interest: $" << interest << endl;
    }
};

class CurrentAccount : public Bank {
public:
    void calculateInterest(double balance) override {
        double interest = balance * 0.02; 
        	cout << "Current Account Interest: $" << interest << endl;
    }
};

int main() {
    double myBalance = 1000.0;
    SavingsAccount S1;
    Bank &B1 = S1;
    B1.calculateInterest(myBalance);
    CurrentAccount C1;
    Bank &B2 = C1;
    B2.calculateInterest(myBalance);
    return 0;
}
