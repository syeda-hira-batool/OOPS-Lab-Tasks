#include<iostream>
#include<string>
using namespace std;
 
class Character {
	public:
    	virtual void performAttack() {
        	cout << "Generic attack!" << endl;
    	}
};
 
class Warrior : public Character {
	public:
    	void performAttack() override {
        	cout << "Warrior performs: Sword Slash!" << endl;
    	}	
};
 
class Mage : public Character {
	public:
    	void performAttack() override {
        	cout << "Mage casts: Fireball!" << endl;
    	}
};
 
class Healer : public Character {
	public:
    	void performAttack() override {
        	cout << "Healer performs: Healing Strike!" << endl;
    	}
};
 
int main() {
    Character* c1 = new Warrior();
    Character* c2 = new Mage();
    Character* c3 = new Healer();
 
    c1->performAttack();
    c2->performAttack();
    c3->performAttack();
 
    delete c1;
    delete c2;
    delete c3;
 
    return 0;
}
