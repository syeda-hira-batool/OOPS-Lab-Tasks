#include <iostream>
using namespace std;

template <class T>
class SensorLog {
	private:
    	T readings[100];
	    int size;
	
	public:
	    SensorLog(T arr[], int s) {
	        size = s;
	        for (int i = 0; i < size; i++) {
	            readings[i] = arr[i];
	        }
	    }
	
	    T getAverage() {
	        T sum = 0;
	        for (int i = 0; i < size; i++) {
	            sum = sum + readings[i];
	        }
	        return sum / size;
	    }
	};

int main() {

    int tempInt[] = {67, 670, 6700, 6770};
    SensorLog<int> S1(tempInt, 4);
    cout << "Average (int): " << S1.getAverage() << endl;

    double tempDouble[] = {67.67, 67.7, 67.8, 679.6};
    SensorLog<double> S2(tempDouble, 4);
    cout << "Average (double): " << S2.getAverage() << endl;

    return 0;
}
