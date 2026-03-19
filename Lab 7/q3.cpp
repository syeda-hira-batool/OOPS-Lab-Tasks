#include <iostream>
#include<string>
using namespace std;

class plugin {
	public:
    	virtual void execute() = 0;  
    	virtual ~plugin() {}         
};

class antivirus : public plugin {
	public:
    	void execute() override {
        	cout << "Scanning system for threats..." << endl;
    	}
};

class updater : public plugin {
	public:
    	void execute() override {
        	cout << "Checking for system updates..." << endl;
    	}
};

int main() {
    
    plugin* plugins[2];
    plugins[0] = new antivirus();
    plugins[1] = new updater();
    
    for (int i = 0; i < 2; i++) {
        plugins[i]->execute();  
    }
    
    for (int i = 0; i < 2; i++) {
        delete plugins[i];
    }

    return 0;
}

