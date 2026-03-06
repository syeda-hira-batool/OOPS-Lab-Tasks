#include <iostream>
#include <string>
using namespace std;

class WeatherStats
{

public:
    // static so can be accesed without any object being made
    static double calculateAverageTemperature(const double temp[], int index)
    {

        double sum = 0;
        double avg;

        for (int i = 0; i < index; i++)
        {
            sum = sum + temp[i];
        }

        avg = sum / index;
        return avg;
    }

    // to avoid modification passing array as constant
    static double getTemperatureFluctuation(const double temp[], int index)
    {

        double high = temp[0];
        double low = temp[0];

        for (int i = 1; i < index; i++)
        {

            if (temp[i] > high)
            {
                high = temp[i];
            }

            if (temp[i] < low)
            {
                low = temp[i];
            }
        }

        double diff = high - low;
        return diff;
    }
};

int main()
{

    double temp[] = {67.0, 45.0, 67.7, 69.2, 68.4};
    int index = 5;

    double avg = WeatherStats::calculateAverageTemperature(temp, index);
    double fluc = WeatherStats::getTemperatureFluctuation(temp, index);

    cout << "Average Temperature: " << avg << endl;
    cout << "Temperature Fluctuation: " << fluc << endl;

    return 0;
}