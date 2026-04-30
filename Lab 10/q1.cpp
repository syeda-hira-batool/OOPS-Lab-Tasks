#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream out("signup.txt", ios::app);

    string name, email;

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter email: ";
    getline(cin, email);

    out << name << "\n" << email << endl;

    out.close();

    cout << "Registration saved successfully";

    return 0;
}
