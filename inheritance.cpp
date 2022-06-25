#include <iostream>
using namespace std;
class Person{
	public:
	string name, surname;
	int age;
	void print (){
		cout << "Person print" << endl; 
		cout << "name is : " << name << endl;
		cout << "surname is : " << surname << endl;
		cout << "age is : " << age << endl;
	}

};

class specialist : public Person {
	public:
		int IQ;
		int languages;
	void print (){
		cout << "specialist print" << endl; 
		cout << "name is : " << name << endl;
		cout << "surname is : " << surname << endl;
		cout << "age is : " << age << endl;
		cout << "IQ is : " << IQ << endl;
		cout << "languages is : " << languages << endl;
	}
};

class medic : public specialist {
	public:
		string experience;
		string salary;
	void print (){
		cout << "specialist print" << endl; 
		cout << "name is : " << name << endl;
		cout << "surname is : " << surname << endl;
		cout << "age is : " << age << endl;
		cout << "IQ is : " << IQ << endl;
		cout << "languages is : " << languages << endl;
		cout << "exp is : " << experience << endl;
		cout << "salary is : " << salary << endl;
	}

};

class surgeon : public medic {
	public:
		string direction;
	void print (){
		cout << "specialist print" << endl; 
		cout << "name is : " << name << endl;
		cout << "surname is : " << surname << endl;
		cout << "age is : " << age << endl;
		cout << "IQ is : " << IQ << endl;
		cout << "languages is : " << languages << endl;
		cout << "exp is : " << experience << endl;
		cout << "salary is : " << salary << endl;
		cout << "dir is : " << direction << endl;
	}

};
class cardio_surgeon : public surgeon {
	public:
		int patients;
	void print (){
		cout << "specialist print" << endl; 
		cout << "name is : " << name << endl;
		cout << "surname is : " << surname << endl;
		cout << "age is : " << age << endl;
		cout << "IQ is : " << IQ << endl;
		cout << "languages is : " << languages << endl;
		cout << "exp is : " << experience << endl;
		cout << "salary is : " << salary << endl;
		cout << "patients is : " << patients << endl;
	}

};

int main() {
	cardio_surgeon c;
	c.name = "T";
	c.surname = "K";
	c.age = 15;
	c.IQ = 150;
	c.languages = 3;
	c.experience = "5";
        c.salary = "1.5b";
	c.direction = "cardio";
	c.patients = 2500;	
	c.print();
	return 0;
}
