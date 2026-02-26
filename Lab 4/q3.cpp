#include <iostream>
using namespace std;

class Satelite
{
public:
    const int date;
    const int ID;
    float radius;
    static int n;

    Satelite(float radiusp) : date(0), ID(0)
    {
        radius = radiusp;
    }

    Satelite(int datep, int IDp) : date(datep), ID(IDp), radius(0)
    {
        cout << "Initializer List to set constant members" << endl;
    }

    void calibrate()
    {
        float r;
        cout << "Enter the radius: " << endl;
        cin >> r;
        radius = r;
    }

    int Dispay() const
    {
        n++;
        cout << "Satelite Info" << endl;
        cout << "==============" << endl;
        cout << "Date: " << date << endl;
        cout << "ID: " << ID << endl;
        cout << "Radius: " << radius << endl;
        return n;
    }
};

int Satelite::n = 0;

int main()
{
    Satelite S1(23, 89);
    S1.Dispay();
    S1.calibrate();
    int s = S1.Dispay();
    cout << "Number of reports view: " << s << endl;

    Satelite S2(3.3);
    S2.Dispay();

    return 0;
}
