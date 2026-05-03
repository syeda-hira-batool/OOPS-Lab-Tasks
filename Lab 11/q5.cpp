#include <iostream>
using namespace std;

int main() {
	
    float num1, num2;

    try {
        cout << "Enter number 1: " << endl;
        cin >> num1 ;
        cout << "Enter number 2: " << endl;
        cin >> num2;

        if (num2 == 0) {
            throw "Math Error: Division by zero";
        }

        cout << "Result = " << num1 / num2 << endl;
    }
    catch (const char* msg) {
        cout << msg << endl;
    }

    return 0;
}
