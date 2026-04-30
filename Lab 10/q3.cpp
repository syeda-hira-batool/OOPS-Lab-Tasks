#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream out("backup_log.txt", ios::app);

    string message;

    cout << "Enter log message: ";
    getline(cin, message);

    out << message << endl;

    streampos size = out.tellp();  // built-in function so that we know the file size (unformmatted)

    cout << "Current file size: " << size << " bytes";

    out.close();

    return 0;
}
