#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>   // uses for character check
using namespace std;

int main() {
    ifstream in("article.txt");  //manually entered data so that it could be stored in report
    ofstream out("report.txt");

    string line;
    int chars = 0, words = 0, lines = 0, punc = 0;

    while (getline(in, line)) {
        lines++;
        chars += line.length();

        for (int i = 0; i < line.length(); i++) {
            if (ispunct(line[i])) {
                punc++;
            }
        }

        istringstream iss(line);
        string word;
        while (iss >> word) {
            words++;
        }
    }

    out << "Characters: " << chars << endl;
    out << "Words: " << words << endl;
    out << "Lines: " << lines << endl;
    out << "Punctuation: " << punc << endl;

    in.close();
    out.close();

    return 0;
}
