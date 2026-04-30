#include <iostream>
#include <fstream>
using namespace std;

int main() {
    fstream file("draft.txt", ios::in | ios::out);   //created the file and manually entered the data
    
    // first see the file and know the typo is the first word

    string word;
    long pos;

    while (file >> word) {
        pos = file.tellg();

        if (word == "teh") {
            cout << "Found typo: " << word << endl;
            file.seekp(pos - (long)word.length() - 1);
            file << "the";
            cout << "Typo corrected to: the" << endl;
            break;
            
            // now the typo is corrected: see the file
        }
    }

    file.close();

    return 0;
}
