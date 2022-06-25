#include <iostream>
using namespace std;
class Person{
	public:
	string name, surname;
	int age;
	void print (){
		cout << "name is : " << name << endl;
		cout << "surname is : " << surname << endl;
		cout << "age is : " << age << endl;
	}

};

class specialist : public Person {
	int IQ;
	int languages;
};

class Medic : public specialist {


};

class surgeon : public specialist {

};
class cardio_surgeon : public specialist {

};

int main() {
	Person p;
	p.name = "T";
	p.surname = "K";
	p.age = 15;
	p.print();
	return 0;
}
