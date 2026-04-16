#include <iostream>
#include <string>
using namespace std;

class SecuritySystem;

class User
{
    string userID;
    string role;
    int accessLevel;

public:
    User(string id, string r, int level)
        : userID(id), role(r), accessLevel(level) {}

    void viewAccessibleDevices()
    {
        cout << "User: " << userID << " - Accessible Devices:\n";
        cout << "- LED Light\n- Ceiling Fan\n- Split AC\n";
    }

    friend void accessSecurityLogs(User &, SecuritySystem &);
};

class Device
{
protected:
    string id, name;
    double power;

public:
    Device(string i, string n, double p)
        : id(i), name(n), power(p) {}

    virtual void turnOn() = 0;
    virtual double calculatePowerUsage(int hours) = 0;

    double operator+(Device &d)
    {
        return power + d.power;
    }

    string getName() { return name; }
};

class Light : public Device
{
public:
    Light(string i, string n, double p)
        : Device(i, n, p) {}

    void turnOn() override
    {
        cout << name << " ID: " << id << " turned ON.\n";
    }

    double calculatePowerUsage(int hours) override
    {
        double usage = power * hours;
        cout << name << ": " << usage << " Watts\n";
        return usage;
    }
};

class Fan : public Device
{
    int speed;

public:
    Fan(string i, string n, double p, int s)
        : Device(i, n, p), speed(s) {}

    void turnOn() override
    {
        cout << name << " ID: " << id << " turned ON at Speed " << speed << ".\n";
    }

    double calculatePowerUsage(int hours) override
    {
        double usage = power * hours;
        cout << name << ": " << usage << " Watts\n";
        return usage;
    }
};

class AirConditioner : public Device
{
    int temp;

public:
    AirConditioner(string i, string n, double p, int t)
        : Device(i, n, p), temp(t) {}

    void turnOn() override
    {
        cout << name << " ID: " << id << " turned ON. Cooling to " << temp << "C\n";
    }

    double calculatePowerUsage(int hours) override
    {
        double usage = power * hours;
        cout << name << ": " << usage << " Watts" << endl;
        return usage;
    }
};

class SecuritySystem : public Device
{
    string logs;

public:
    SecuritySystem(string i, string n, double p)
        : Device(i, n, p)
    {
        logs = "- Intrusion Detected at 3:00 AM\n so System Reset Required";
    }

    void turnOn() override
    {
        cout << name << " ID: " << id << " activated" << endl;
    }

    double calculatePowerUsage(int hours) override
    {
        double usage = power * hours;
        cout << "Security System: " << usage << " Watts" << endl;
        return usage;
    }

    friend void accessSecurityLogs(User &, SecuritySystem &);
};

void accessSecurityLogs(User &u, SecuritySystem &s)
{
    if (u.role == "Maintenance Staff")
    {
        cout << "User: " << u.userID << " - Security Logs Accessed:\n";
        cout << s.logs << endl;
    }
}

int main()
{

    User user1("U001", "Regular User", 1);
    User user2("U002", "Maintenance Staff", 2);

    Light light1("L001", "LED Light", 10);
    Fan fan1("F001", "Ceiling Fan", 75, 3);
    AirConditioner ac1("AC001", "Split AC", 1500, 25);
    SecuritySystem secSys1("S001", "Home Alarm", 100);

    light1.turnOn();
    fan1.turnOn();
    ac1.turnOn();
    secSys1.turnOn();

    cout << "\nPower Consumption:\n";

    light1.calculatePowerUsage(5);
    fan1.calculatePowerUsage(3);
    ac1.calculatePowerUsage(6);
    secSys1.calculatePowerUsage(24);

    cout << endl;

    user1.viewAccessibleDevices();
    accessSecurityLogs(user2, secSys1);

    return 0;
}
