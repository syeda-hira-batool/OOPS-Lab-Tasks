#include <iostream>
#include <string>
using namespace std;

template <class T>
int findItem(T a[], int size, T search) {
    for (int i = 0; i < size; i++) {
        if (a[i] == search) {
            return i;
        }
    }
    return -1;
}

int main() {

    int ids[] = {670, 671, 672, 673};
    int size1 = 4;

    int searchID = 670;
    int result1 = findItem(ids, size1, searchID);

    if (result1 != -1)
        cout << "Product ID found at index: " << result1 << endl;
    else
        cout << "Product ID not found\n";

    string names[] = {"Bluetooth", "Cortis", "Sunghoon", "MinnieMouse"};
    int size2 = 4;

    string searchName = "Sunghoon";
    int result2 = findItem(names, size2, searchName);

    if (result2 != -1)
        cout << "Product Name found at index: " << result2 << endl;
    else
        cout << "Product Name not found\n";

    return 0;
}
