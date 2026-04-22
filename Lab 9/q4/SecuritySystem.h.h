#ifndef SECURITYSYSTEM_H
#define SECURITYSYSTEM_H

#include <iostream>
using namespace std;

class SecurityDevice {
	public:
    	virtual void authenticate() = 0;  
    	virtual ~SecurityDevice() {}     
};

class BiometricScanner : public SecurityDevice {
	private:
    	int attempts;

	public:
    	BiometricScanner();   
    	void authenticate();  
};

#endif
