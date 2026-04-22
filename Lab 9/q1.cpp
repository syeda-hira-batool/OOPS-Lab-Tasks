#include<iostream>
using namespace std;

class CoffeeMachine{
	private:
		int waterLevel;
		int coffeeBeans;
	public:
		CoffeeMachine(int w, int c){
			waterLevel = w;
			coffeeBeans = c;
		}
		void makeCoffee(){
			if(waterLevel < 100){
				cout << "Insufficient Water" << endl;
				return ;
			}
			waterLevel--;
			cout << "Coffee is Ready" << endl;
		}
};

int main(){
	
	CoffeeMachine cm1(200 , 100);
	cm1.makeCoffee();
	CoffeeMachine cm2(67 , 700);
	cm2.makeCoffee();
	
	return 0;
}
