#include <iostream>
#include <regex>
using namespace std;

void searcher(string& text,regex& r){
	smatch cor;
	while(regex_search(text, cor,r)) {
		cout << cor[0] << endl;
		text = cor.suffix().str();
	}

}


int main(){
	regex vivacell("(\\(?0(77|94|98)\\)?|\\+(\\(?374\\)?)\\s?(77|94|98))\\s?([0-9]{2}[-\\s]?){2}[0-9]{2}");
	regex teams("(\\(?0(33|43|91|96|99)\\)?|\\+(\\(?374\\)?)\\s?(33|43|91|96|99))\\s?([0-9]{2}[-\\s]?){2}[0-9]{2}");
	regex ucom("(\\(?0(55|95)\\)?|\\+(\\(?374\\)?)\\s?(55|95))\\s?([0-9]{2}[-\\s]?){2}[0-9]{2}");
	regex passport("[A][A-Z][0-9]{7}");
	regex date("(([0-2][0-9])|(3[0-1]))[\\/\\.\\-]((0[0-9])|(1[0-2]))[\\/\\.\\-][0-2][0-9]{3}");
	regex name ("\\b([A-Z][a-z]{1,}\\s+(!Ham)[A-Z][a-z]{1,}(ian|yan|uni|enc|deh|toc))\\b");
	regex ipv4("(((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9]{1}))\\.){3}((25[0-5])|(2[0-4][0-9])|(1[0-9]{2})|([1-9][0-9])|([0-9]{1}))");
	//regex ipv6("(((([1-9A-F])([0-9]|[A-F]){2,3})|(([1-9]|[A-F])([0-9]|[A-F]))|([0-9]|[A-F]))\\:){3}(((([1-9]|[A-F])([0-9]|[A-F]){2,3})|(([1-9]|[A-F])([0-9]|[A-F]))|([0-9]|[A-F])))",regex_constants::icase);
	regex ipv6("((([1-9A-F][0-9A-F]{2,3})|([1-9A-F][0-9A-F])|([0-9A-F]))\\:){7}(([1-9A-F][0-9A-F]{2,3})|([1-9A-F][0-9A-F])|([0-9A-F]))",regex_constants::icase);
	
	string viv_t = "Phone numbers people display in different ways: 094 54 54 54 or +37494545454 you can also use +(374)94 54-54-54 this form or (093)54-54-54. But it's also accepted way to use this form  (077) 54 54 54 and  +374 98 54 54 54.";
	string ucom_t = "Phone numbers people display in different ways: 094 54 54 54 or +37494545454 you can also use +(374)94 54-54-54 this form or (055)54-54-54. But it's also accepted way to use this form  (095) 54 54 54 and  +374 55 54 54 54.";
	string teams_t = "Phone numbers people display in different ways: 033 54 54 54 or +37443545454 you can also use +(374)91 54-54-54 this form or (096)54-54-54. But it's also accepted way to use this form  (094) 54 54 54 and  +374 99 54 54 54.";
	string passport_t = "Passport seria: AN1444442 .";
	string name_t = "Yeghishe Charenc is a famous writer and Henrikh Mkhitaryan is a famous foolball player.";
	string date_t = "Jane birthday is on 29.07.1998 and Jane brother's birthday is on 22-11-1995 or 31.15.2015";
	string ip4_t = "IPv4 form is : 0.255.15.0 or 15.155.49.9 or 255.255.255.249 but not 15..45.47.49 or 99.65.41 or 15.15 or 12";
	string ip6_t = "IPv6 form is : 0:2F:AB:570:4F:1a:FFFF:78 or 15:FFFa:2a:97B:1a:48D:47:255 or 25a:2f5:2:147:444a:5D:47c:12a but not 15::4b5:47a:49 or 919:ff:m or a:0 or 0";
	
	cout << "---------"<< endl;	
	searcher(viv_t,vivacell);	
	cout << "---------"<< endl;	
	searcher(teams_t,teams);	
	cout << "---------"<< endl;	
	searcher(ucom_t,ucom);	
	cout << "---------"<< endl;	
	searcher(passport_t,passport);	
	cout << "---------"<< endl;	
	searcher(date_t,date);	
	cout << "---------"<< endl;	
	searcher(name_t,name);	
	cout << "----IPv4-----"<< endl;	
	searcher(ip4_t,ipv4);	
	cout << "----IPv6-----"<< endl;	
	searcher(ip6_t,ipv6);	
	
	return 0;
		
}
