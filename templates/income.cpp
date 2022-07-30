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
	double sum() const{
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
	
	bool operator<(const Income& t) {
		return (this->sum() < t.sum()); 
	}

	bool operator>=(const Income& t) {
		return (this->sum() >= t.sum()); 
	}

	bool operator<=(const Income& t) {
		return (this->sum() <= t.sum()); 
	}
	
	const Income operator*(const Income& t) {
		Income temp;
		temp.fromShop = this->fromShop * t.fromShop;
		temp.fromTenders = this->fromTenders * t.fromTenders;
		temp.fromApps = this->fromApps * t.fromApps;
                temp.fromEducation= this->fromEducation * t.fromEducation;
		temp.fromConsulting = this->fromConsulting * t.fromConsulting;
		
		return temp; 
	}
	const Income operator*=(const Income& t) {
	//	return (*this+t);
		this->fromShop *= t.fromShop;
		this->fromTenders *= t.fromTenders;
		this->fromApps *= t.fromApps;
                this->fromEducation *= t.fromEducation;
		this->fromConsulting *= t.fromConsulting;
		return *this;
	}

	const Income operator/(const Income& t) {
		Income temp;
		temp.fromShop = this->fromShop / t.fromShop;
		temp.fromTenders = this->fromTenders / t.fromTenders;
		temp.fromApps = this->fromApps / t.fromApps;
                temp.fromEducation= this->fromEducation / t.fromEducation;
		temp.fromConsulting = this->fromConsulting / t.fromConsulting;
		
		return temp; 
	}
	const Income operator/=(const Income& t) {
	//	return (*this+t);
		this->fromShop /= t.fromShop;
		this->fromTenders /= t.fromTenders;
		this->fromApps /= t.fromApps;
                this->fromEducation /= t.fromEducation;
		this->fromConsulting /= t.fromConsulting;
		return *this;
	}
	const Income operator+(const Income& t) {
                cout << "hello" << endl;
		Income temp;
		temp.fromShop = this->fromShop + t.fromShop;
		temp.fromTenders = this->fromTenders + t.fromTenders;
		temp.fromApps = this->fromApps + t.fromApps;
                temp.fromEducation= this->fromEducation + t.fromEducation;
		temp.fromConsulting = this->fromConsulting + t.fromConsulting;
		
		return temp; 
	}
	const Income operator+=(const Income& t) {
	//	return (*this+t);
		this->fromShop += t.fromShop;
		this->fromTenders += t.fromTenders;
		this->fromApps += t.fromApps;
                this->fromEducation += t.fromEducation;
		this->fromConsulting += t.fromConsulting;
		return *this;
	}
	const Income operator++() {
	//	return (*this+t);
		this->fromShop++;
		this->fromTenders++;
		this->fromApps++;
                this->fromEducation++;
		this->fromConsulting++;
		return *this;
	}
	const Income operator++( int ch) {
	//	return (*this+t);
                Income temp = *this;
		this->fromShop++;
		this->fromTenders++;
		this->fromApps++;
                this->fromEducation++;
		this->fromConsulting++;
                //temp.print();
		//cout<< "Temp is ----------" <<endl;
		return temp;
	}
	const Income operator-(const Income& t) {
		Income temp;
		temp.fromShop = this->fromShop - t.fromShop;
		temp.fromTenders = this->fromTenders - t.fromTenders;
		temp.fromApps = this->fromApps - t.fromApps;
                temp.fromEducation= this->fromEducation - t.fromEducation;
		temp.fromConsulting = this->fromConsulting - t.fromConsulting;
		
		return temp; 
	}
	const Income operator-=(const Income& t) {
	//	return (*this-t);
		this->fromShop -= t.fromShop;
		this->fromTenders -= t.fromTenders;
		this->fromApps -= t.fromApps;
                this->fromEducation -= t.fromEducation;
		this->fromConsulting -= t.fromConsulting;
		return *this;
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
	cout << "Mult value is :" << endl;
	Income k = i * i1;
	k.print();
	cout << "------------------- += value is :" << endl;
	i+=i1;
	i.print();
	cout << "-------------------- *= value is :" << endl;
	i*=i1;
	i.print();
	cout << "---------------------- /= value is :" << endl;
	i/=i1;
	i.print();
	cout << "------------------------ -= value is :" << endl;
	i-=i1;
	i.print();
	cout << "------------------------ prefix ++ value is :" << endl;
	Income ch = i++;
	ch.print();
        cout << "------------------------------------- i value is : " << endl;
	i.print();
	cout << "------------------------ postfix ++ value is :" << endl;
	Income m = ++i;
	m.print();
        cout << "---------------------------------- original value is : " << endl;
	i.print();
	return 0;
}
