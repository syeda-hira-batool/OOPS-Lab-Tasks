#include <iostream>
using namespace std;

int main() {
	
    int age;

    try {
        cout << "Enter your age: ";
        cin >> age;

        if (age < 18) {
            throw age;   
        }

        cout << "You are eligible to vote" << endl;
    }
    catch (int a) {
        cout << "Ineligible to vote! " << endl;
    }

    return 0;
}
