#include "SecuritySystem.h"

BiometricScanner::BiometricScanner() {
    attempts = 0;
}

void BiometricScanner::authenticate() {
    int id;

    while (attempts < 3) {
        cout << "Enter Fingerprint ID: ";
        cin >> id;

        if (id == 1234) {
            cout << "Access Granted." << endl;
            return;
        } else {
            attempts++;
            cout << "Incorrect ID." << endl;
        }
    }

    cout << "System Locked!" << endl;
}
