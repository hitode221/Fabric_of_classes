#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Base {
protected:
	int value;
public:
	Base() : value(0) {};
	Base(int val) : value(val) {};
	virtual void show() = 0;
};

class A: public Base{
public:
	A() : Base() {};
	A(int val) : Base(val) {};
	void show(){ cout << "class A: " << value << endl;}
};

class B: public Base{
public:
	B() : Base() {};
	B(int val) : Base(val) {};

	void show(){ cout << "class B: " << value << endl;}
};

class C: public Base{
public:
	C() : Base() {};
	C(int val) : Base(val) {};
	void show(){ cout << "class C: " << value << endl;}
};

Base* Create(char name, int val){
	Base * object;
	if (name == 'A') object = new A(val);
	if (name == 'B') object = new B(val);
	if (name == 'C') object = new C(val);
	return object;
}

int main(){
	vector<Base*> objects;
	int n, value;
	char class_name;
	string action;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> action;
		if(action == "create"){
			cin >> class_name >> value;
			objects.push_back(Create(class_name, value));
		}
		else if(action == "showall") 
			for(int i = 0; i < objects.size(); i++)
				objects[i]->show();
		else cout << "Incorrect operation\n"; 
	}
	system("pause");
	return 0;
}
