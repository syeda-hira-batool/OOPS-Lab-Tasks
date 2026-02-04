#include <iostream>
#include "Employee.h"
using namespace std;

void Employee::setinfo(long long bs, string id, string name, float hr) {
    BaseSalary = bs;
    EmployeeID = id;
    Name = name;
    hrs = hr;
}

long long Employee::calculateTotalSalary() {
    long long totalSalary = BaseSalary;

    if (hrs > 40) {
        float overtimeHours = hrs - 40;
        float hourlyRate = BaseSalary / 40.0;
        totalSalary += overtimeHours * hourlyRate * 1.5;
    }

    return totalSalary;
}

void Employee::display() {
    cout << "Employee Name: " << Name << endl;
    cout << "Employee ID: " << EmployeeID << endl;
    cout << "Base Salary: " << BaseSalary << endl;
    cout << "Hours Worked: " << hrs << endl;
    cout << "Total Salary: " << calculateTotalSalary() << endl;
    cout << "----------------------" << endl;
}
