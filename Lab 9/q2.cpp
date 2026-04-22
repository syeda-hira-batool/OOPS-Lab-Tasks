#include<iostream>
using namespace std;

class Payment{
	public:
		virtual double processPayment(double amount) = 0;
		
};

class CreditCard : public Payment{
	public:
		double processPayment(double amount){
			amount = amount + (0.02 * amount);
			cout << "Processing Credit Card payment of " << amount << endl;
		}		
};

class PayPal : public Payment{
	public:
		double processPayment(double amount){
			if (amount > 500){
				amount = amount - 10;
				cout << "Processing PayPal payment: " << amount << endl;
			}
			else{
				cout << "Processing PayPal payment: " << amount << endl;
			}
		}
};

int main(){
	
	Payment *p1;
	CreditCard c1;
	PayPal pp1;
	p1 = &c1;
	p1->processPayment(200);
	p1 = &pp1;
	p1->processPayment(670);
	p1->processPayment(200);
	
	return 0;
}

