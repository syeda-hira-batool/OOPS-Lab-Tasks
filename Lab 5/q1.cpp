#include <iostream>
#include <string>
using namespace std;

class Order
{
private:
    static int count;

public:
    int id;
    string customer;
    string restaurant;
    string foodItem;

    Order() {}

    Order(string customer, string restaurant, string foodItem)
    {
        id = ++count;
        this->customer = customer;
        this->restaurant = restaurant;
        this->foodItem = foodItem;
    }

    void show()
    {
        cout << "Order ID: " << id << endl;
        cout << "Customer: " << customer << endl;
        cout << "Restaurant: " << restaurant << endl;
        cout << "Food Item: " << foodItem << endl;
        cout << "-------------------------" << endl;
    }
};

int Order::count = 0;

class Restaurant
{
public:
    string name;

    Order orders[10];
    int orderCount = 0;

    Restaurant(string name)
    {
        this->name = name;
    }

    void takeOrder(Order o)
    {
        if (orderCount < 10)
        {
            orders[orderCount++] = o;
            cout << "Restaurant " << name << " received the order.\n";
        }
        else
        {
            cout << "Order list full!\n";
        }
    }

    void showAllOrders()
    {
        cout << "\nAll Orders at " << name << ":\n";
        for (int i = 0; i < orderCount; i++)
        {
            orders[i].show();
        }
    }
};

class Customer
{
public:
    string name;

    Customer(string name)
    {
        this->name = name;
    }

    void placeOrder(Restaurant *r, string food)
    {
        cout << name << " is placing an order for " << food
             << " at " << r->name << endl;

        Order newOrder(name, r->name, food);
        r->takeOrder(newOrder);
    }
};

int main()
{

    Customer c1("Soha");
    Customer c2("Batool");

    Restaurant r1("Pizza Hut");

    c1.placeOrder(&r1, "Pizza");
    c2.placeOrder(&r1, "Shawarma");

    r1.showAllOrders();

    return 0;
}
