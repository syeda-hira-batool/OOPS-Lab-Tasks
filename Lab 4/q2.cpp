#include <iostream>
using namespace std;

class Circle
{
public:
    const float pi = 3.142;
    float r;

    void InputR()
    {
        cout << "Enter the radius: ";
        cin >> r;
    }

    float Area() const
    {
        return r * pi * r;
    }
};

int main()
{
    Circle C1;
    C1.InputR();

    float area1 = C1.Area();
    cout << "Area: " << area1 << endl;

    return 0;
}
