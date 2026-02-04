#include <iostream>
using namespace std;

int marks[5];

void display()
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Marks of student " << i + 1 << ": " << marks[i] << endl;
    }
}

int main()
{

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter the Student " << i + 1 << " marks: " << endl;
        cin >> marks[i];
    }

    display();

    int sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum = sum + marks[i];
    }
    cout << "Total Marks: " << sum << endl;

    float avg = sum / 5;
    cout << "Average Marks: " << avg << endl;

    if (avg >= 50)
    {
        cout << "Result: PASS" << endl;
    }

    return 0;
}

// q1