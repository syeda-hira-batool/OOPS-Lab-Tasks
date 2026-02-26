#include <iostream>
using namespace std;

class Employee
{

public:
    int ID;
    string name;
    long long salary;
    static int n;

    void AddInfo()
    {
        cin.ignore();

        cout << "Enter the name of Employee: " << endl;
        getline(cin, name);

        cout << "Enter the salary of Employee: " << endl;
        cin >> salary;
    }

    void Assign()
    {
        ID = 1000 + (++n);
    }

    void Details()
    {
        cout << "Name: " << name << endl;
        cout << "ID: " << ID << endl;
        cout << "Salary: " << salary << endl;
    }

    static void displayn()
    {
        cout << "Number of Employees: " << n << endl;
    }
};

int Employee::n = 0;

int main()
{

    Employee E1, E2, E3, E4;

    E1.AddInfo();
    E1.Assign();
    E1.Details();
    Employee::displayn();
    cout << "-------------------" << endl;
    E2.AddInfo();
    E2.Assign();
    E2.Details();
    Employee::displayn();
    cout << "-------------------" << endl;
    E3.AddInfo();
    E3.Assign();
    E3.Details();
    Employee::displayn();
    cout << "-------------------" << endl;
    E4.AddInfo();
    E4.Assign();
    E4.Details();
    Employee::displayn();
    cout << "-------------------" << endl;
    Employee E5;
    E5.AddInfo();
    E5.Assign();
    E5.Details();
    Employee::displayn();
    cout << "-------------------" << endl;

    return 0;
}
