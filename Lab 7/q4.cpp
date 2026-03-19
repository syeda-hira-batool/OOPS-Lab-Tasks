#include <iostream>
#include<string>
using namespace std;

class staff {
	protected:
    	string name;

	public:
    	staff(string n) : name(n) {}

    	virtual double processSalary() const = 0;

    	string getName() const {
        	return name;
    	}

    	virtual ~staff() {}
};

class SalariedEmployee : public staff {
	private:
    	double fixedSalary;

	public:
    	SalariedEmployee(string n, double salary) : staff(n), fixedSalary(salary) {}

    	double processSalary() const override {
        	return fixedSalary;
    	}
};

class CommissionEmployee : public staff {
	private:
    	double sales;
    	double percentage;

	public:
    	CommissionEmployee(string n, double s, double p) : staff(n), sales(s), percentage(p) {}

    	double processSalary() const override {
        	double sale = sales * (percentage / 100);
        	return sale;
    	}
};

int main() {
    const int count = 2;

    staff* employees[count];

    employees[0] = new SalariedEmployee("Batool", 6767);
    employees[1] = new CommissionEmployee("Hira", 676767, 67);

    cout << "------ Payroll System ------" << endl;

    for (int i = 0; i < count; i++) {
        cout << "Name: " << employees[i]->getName()
             << " | Salary: " << employees[i]->processSalary() << endl;
    }

    for (int i = 0; i < count; i++) {
        delete employees[i];
    }

    return 0;
}
