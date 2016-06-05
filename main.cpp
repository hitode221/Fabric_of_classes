#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

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
	void show(){ cout<< "class A: "<< value << endl;}
};

class B: public Base{
public:
	B() : Base() {};
	B(int val) : Base(val) {};

	void show(){ cout<< "class B: "<< value << endl;}
};

class C: public Base{
public:
	C() : Base() {};
	C(int val) : Base(val) {};
	void show(){ cout<< "class C: " << value << endl;}
};

vector<Base*> objects;

void Create(char name, int val){
	Base * object;
	switch(name){
	case 'A':
		object = new A(val);
		break;
	case 'B':
		object = new B(val);
		break;
	case 'C':
		object = new C(val);
		break;
	default:
		throw "error";
	}
	objects.push_back(object);
}

void ShowAll(){
	for(int i = 0; i < objects.size(); i++)
		objects[i]->show();
}

int main(){
	int n, value;
	char class_name;
	string action;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> action;
		if(action == "create"){
			cin >> class_name >> value;
			Create(class_name, value);
		}
		else if(action == "showall") 
			ShowAll();
		else cout << "Incorrect operation\n"; 
	}
	system("pause");
	return 0;
}
