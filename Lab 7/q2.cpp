#include <iostream>
#include <string>
using namespace std;

class staff {
protected:
    string name;

public:
    staff(string n) : name(n) {}

    virtual double calculateSalary() const = 0;

    string getName() const {
        return name;
    }

    virtual ~staff() {}
};

class contractor : public staff {
private:
    double hoursWorked;
    double rate;

public:
    contractor(string n, double h, double r) : staff(n), hoursWorked(h), rate(r) {}

    double calculateSalary() const override {
        return hoursWorked * rate;
    }
};

class FullTimeEmployee : public staff {
private:
    double base;
    double bonus;

public:
    FullTimeEmployee(string n, double ba, double b) : staff(n), base(ba), bonus(b) {}

    double calculateSalary() const override {
        return base + bonus;
    }
};

int main() {
    const int count = 2;

    staff* payroll[count];

    payroll[0] = new contractor("Batool", 67, 67.9);
    payroll[1] = new FullTimeEmployee("Hira", 6767, 670);

    cout << "----------------------------" << endl;

    for (int i = 0; i < count; ++i) {
        cout << "Name: " << payroll[i]->getName()
             << " | Calculated Salary: $" << payroll[i]->calculateSalary() << endl;
    }

    for (int i = 0; i < count; ++i) {
        delete payroll[i];
    }

    return 0;
}
