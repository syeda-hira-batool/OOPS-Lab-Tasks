#include <iostream>
#include <fstream>
#include <cctype>   //use the character lib for the isupper() built-in function
using namespace std;

int main() {
    ifstream in("secret.txt"); //not made, so i made one and added the data

    char ch;
    int count = 0;

    while (in.get(ch)) {
        if (isupper(ch)) {
            count++;
        }
    }

    in.close();

    cout << "Uppercase letters: " << count << endl;

    return 0;
}
