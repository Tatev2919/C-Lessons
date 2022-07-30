#include <iostream>
using namespace std;

class Income{
	public:
		double fromShop;
		double fromTenders;
		double fromApps;
		double fromEducation;
		double fromConsulting;
	
	Income() {}
	Income ( double fromShop,double fromTenders,double fromApps,double fromEducation,double fromConsulting ) {
		this->fromShop = fromShop;
		this->fromTenders = fromTenders;
		this->fromApps = fromApps;
                this->fromEducation= fromEducation;
		this->fromConsulting = fromConsulting;
	}

	Income (const Income& t ) {
		this->fromShop = t.fromShop;
		this->fromTenders = t.fromTenders;
		this->fromApps = t.fromApps;
                this->fromEducation= t.fromEducation;
		this->fromConsulting = t.fromConsulting;
	}
	double sum() {
		return (this->fromShop+this->fromTenders+this->fromApps+this->fromEducation+this->fromConsulting);
	}

	bool operator==(const Income& t) {
		return ((this->fromShop==t.fromShop)&& (this->fromTenders==t.fromTenders)&& (this->fromApps == t.fromApps) && (this->fromEducation==t.fromEducation) && (this->fromConsulting== t.fromConsulting)); 
	}

	bool operator!=(const Income& t) {
		return !(*this==t); 
	}

	bool operator>(const Income& t) {
		return (this->sum() > t.sum()); 
	}
	void print () {
		cout <<"fromShop: " << fromShop << endl;
		cout << "fromTenders: " << fromTenders<<endl;
		cout << "fromApps: " <<  fromApps << endl;
                cout << "fromEducation: "<<  fromEducation << endl;
		cout << "fromConsulting: " << fromConsulting << endl;
	}
	
};


int main() {
	Income i(100,250,300,600,470);	
	Income i1(101,250,300,600,470);	
	i.print();
        if (i==i1){
		cout << "equal" << endl;
	} else {
		cout << "not equal" << endl;
	}
        if (i!=i1){
		cout << "not equal" << endl;
	} else {
		cout << "equal" << endl;
	}
        if (i>i1){
		cout << "i more than i1" << endl;
	} else {
		cout << "i1 more than i" << endl;
	}
	return 0;
}
