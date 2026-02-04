#include <iostream>
#include "Employee.h"
using namespace std;

int main() {

    Employee E1, E2;

    E1.setinfo(100000, "101", "Ahmed", 68);
    E2.setinfo(200000, "102", "Ali", 67);

    if (E1.calculateTotalSalary() > E2.calculateTotalSalary()) {
        cout << E1.Name << " has more salary" << endl;
    } else {
        cout << E2.Name << " has more salary" << endl;
    }

    E1.display();
    E2.display();

    return 0;
}
