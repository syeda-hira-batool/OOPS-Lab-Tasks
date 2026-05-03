#include <iostream>
using namespace std;

template <class T>
class Processor {
	public:
	    T reciprocal(T x) {
	        if (x == 0) {
	            throw "Cannot calculate reciprocal of zero";
	        }
	        return 1 / x;
	    }
};

int main() {
	
    Processor<double> p;
    double value;

    try {
        cout << "Enter a number: ";
        cin >> value;

        double result = p.reciprocal(value);
        cout << "Reciprocal = " << result << endl;
    }
    catch (...) {
        cout << "System Failure\n";
    }

    return 0;
}
