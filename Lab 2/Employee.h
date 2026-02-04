#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
using namespace std;

class Employee {
private:
    long long BaseSalary;
    string EmployeeID;

public:
    string Name;
    float hrs;

    void setinfo(long long bs, string id, string name, float hr);
    long long calculateTotalSalary();
    void display();
};

#endif
