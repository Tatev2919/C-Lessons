#include<iostream>
#include <regex>
#include<fstream>
using namespace std;

int main(){
	ifstream read;
	read.open("source");
	string s;

	//regex ipv4("^IP*");
	regex ipv4("notation\\.$");
	regex ipv6("\\b((([1-9A-F][0-9A-F]{2,3})|([1-9A-F][0-9A-F])|([0-9A-F]))\\:){7}(([1-9A-F][0-9A-F]{2,3})|([1-9A-F][0-9A-F])|([0-9A-F])\\b)",regex_constants::icase);

	smatch cor;
	ofstream write;
	write.open("res");
	write << "IPv4 ips in source file are: \n"; 
	
	while(getline(read,s)){
		while(regex_search(s, cor,ipv4)) {
			write << cor[0] << "\n";
			s = cor.suffix().str();
		}
	}

	write.close();
	read.close();
}	
