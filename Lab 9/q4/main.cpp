#include "SecuritySystem.h"

int main() {

    SecurityDevice* device = new BiometricScanner(); 
    device->authenticate();

    delete device;

    return 0;
}
