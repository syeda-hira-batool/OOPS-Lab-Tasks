#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
class Record {
	private:
	    T1 data1;   
	    T2 data2;   
	
	public:
	    void setData(T1 d1, T2 d2) {
	        data1 = d1;
	        data2 = d2;
	    }
	    void display() {
	        cout << "First value: " << data1 << endl;
	        cout << "Second value: " << data2 << endl;
	    }
};

int main() {

    Record<int, double> student1;
    student1.setData(167, 3.67);

    cout << "Record 1 (ID + GPA):\n";
    student1.display();

    cout << endl;

    Record<string, int> student2;
    student2.setData("Han", 18);

    cout << "Record 2 (Name + Age):\n";
    student2.display();

    return 0;
}
