#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int rollNumber;
    string name;
    int marks[3];
    float cgpa;
};

void input(Student *students, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter Student " << i + 1 << " roll number: " << endl;
        cin >> students[i].rollNumber;
        cin.ignore();
        cout << "\nEnter Student " << i + 1 << " name: " << endl;
        getline(cin, students[i].name);
        cout << "\nEnter Student " << i + 1 << " marks for 3 subjects: " << endl;
        for (int j = 0; j < 3; j++)
        {
            cout << "Subject " << j + 1 << ": ";
            cin >> students[i].marks[j];
        }
    }
}

void CGPA(Student *students, int n)
{
    for (int i = 0; i < n; i++)
    {
        int total = 0;
        for (int j = 0; j < 3; j++)
        {
            total += students[i].marks[j];
        }
        students[i].cgpa = total / 30.0;
    }
}

void EligibleStudents(Student *students, int n)
{
    cout << "\nStudents with CGPA >= 3.0:\n";
    for (int i = 0; i < n; i++)
    {
        if (students[i].cgpa >= 3.0)
        {
            cout << "Name: " << students[i].name << endl;
        }
    }
}

void TopPerformer(Student *students, int n)
{

    float maxCgpa = students[0].cgpa;
    for (int i = 1; i < n; i++)
    {
        if (students[i].cgpa > maxCgpa)
        {
            maxCgpa = students[i].cgpa;
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (students[i].cgpa == maxCgpa)
        {
            count++;
        }
    }
    cout << "\nTop Performer(s):\n";
    if (count == n)
    {
        cout << "All students are Top Performers\n";
        for (int i = 0; i < n; i++)
        {
            cout << "Name: " << students[i].name << endl;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (students[i].cgpa == maxCgpa)
            {
                cout << "Name: " << students[i].name << endl;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student *students = new Student[n];

    input(students, n);
    CGPA(students, n);
    EligibleStudents(students, n);
    TopPerformer(students, n);

    delete[] students;

    return 0;
}