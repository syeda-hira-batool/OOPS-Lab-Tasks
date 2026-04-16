//Question 1: 

/* yes, it can be used to overload an operator that modifies the invoking object (like +=),
 but the object in that must be passed by reference.
  for ex: */
  
#include <iostream>
using namespace std;

class CountingMachine {
private:
    int num;

public:
    CountingMachine(int n = 0) : num(n) {}
    friend CountingMachine& operator+=(CountingMachine &obj, int number);

    void display() {
        cout << "Value: " << num << endl;
    }
};

CountingMachine& operator+=(CountingMachine &obj, int number) {
    obj.num += number;
    return obj; 
}

int main() {
    CountingMachine c1(67);

    c1 += 67;

    c1.display();

    return 0;
}

/* Question 2: 

	yes, it is actually the way to handle operations where a primitive type is the first operand. If you use a member function for object + int,
	the object must always be on the left. However, if you want to support int + object, a member function cannot be used because you cannot 
	add a member function to a primitive type like int. 

  for ex: */
  
#include <iostream>
using namespace std;

class Distance {
	private:
    	int meters;
	public:
    	Distance(int m) : meters(m) {}

    	friend Distance operator+(int val, const Distance &obj);

    	void display() { cout << meters << " meters" <<endl; }
};

Distance operator+(int val, const Distance &obj) {
    return Distance(val + obj.meters);
}

int main() {
    Distance d1(50);
    Distance d2 = 20 + d1; 
    d2.display(); 
    return 0;
}


/* Question 3: 
	no, it cannot access non-static private or protected members without an object. A  friend function has "permission" to see private members, 
	it is not a member of the class. It does not have a this pointer so it has no knowledge of which object's data it should look at 
	unless you pass an object to it. Only if the member is static then it can access it directly.
	It will fail if you try to reference a non-static variablewithout the dot or arrow.

  for ex: */
  
#include <iostream>
using namespace std;

class Secret {
	private:
    	int data = 67;
    	static int sharedData;
	public:
    	friend void reveal(Secret &s);
};

int Secret::sharedData = 670;

void reveal(Secret &s) {
    
    cout << "Object data: " << s.data << endl;

    cout << "Static data: " << Secret::sharedData << endl;
    
    // FAIL: cout << data; as:
    // Error: 'data' is not a global variable, the function doesn't know whose 'data' to print.
}

int main() {
    Secret mySecret;
    reveal(mySecret);
    return 0;
}


