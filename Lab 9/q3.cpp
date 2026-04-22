#include <iostream>
using namespace std;

class Package {
private:
    double weight;

public:
    Package(double w) {
        weight = w;
    }

    double getWeight() const {
        return weight;
    }

    virtual double calculateCost() = 0;  
    virtual ~Package() {}
};

class LocalPackage : public Package {
public:
    LocalPackage(double w) : Package(w) {}

    double calculateCost() {
        double cost = getWeight() * 5;

        if (getWeight() > 20) {
            cost += 15;  
        }

        return cost;
    }
};

class InternationalPackage : public Package {
public:
    InternationalPackage(double w) : Package(w) {}

    double calculateCost() {
        return (getWeight() * 15) + 25; 
    }
};

int main() {

    Package* p1 = new LocalPackage(67);
    Package* p2 = new LocalPackage(67);
    Package* p3 = new InternationalPackage(67);

    cout << "Local Package: " << p1->calculateCost() << endl;
    cout << "Local Package: " << p2->calculateCost() << endl;
    cout << "International Package: " << p3->calculateCost() << endl;

    delete p1;
    delete p3;

    return 0;
}
