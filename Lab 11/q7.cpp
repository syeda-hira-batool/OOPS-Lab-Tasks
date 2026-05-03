#include <iostream>
#include <string>
using namespace std;

void checkSecurity(string pass) {

    if (pass.length() < 8) {
        throw 1;   
    }

    bool hasDigit = false;

    for (int i = 0; i < pass.length(); i++) {
        if (isdigit(pass[i])) {
            hasDigit = true;
            break;
        }
    }

    if (!hasDigit) {
        throw 0.1;  
    }

    cout << "Password is valid.\n";
}

int main() {
    string password;

    cout << "Enter password: ";
    cin >> password;

    try {
        checkSecurity(password);
    }
    catch (int) {
        cout << "Error: Password too short. Use at least 8 characters" << endl;
    }
    catch (double) {
        cout << "Error: Password must include at least one numeric digit" << endl;
    }

    return 0;
}
