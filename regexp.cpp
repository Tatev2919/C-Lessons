#include <iostream>
#include <regex>
using namespace std;

int main(){
	regex vivacell("(\\(?0(77|94|98)\\)?|\\+(\\(?374\\)?)\\s?(77|94|98))\\s?([0-9]{2}[-\\s]?){2}[0-9]{2}");
	regex teams("(\\(?0(33|43|91|96|99)\\)?|\\+(\\(?374\\)?)\\s?(33|43|91|96|99))\\s?([0-9]{2}[-\\s]?){2}[0-9]{2}");
	regex ucom("(\\(?0(55|95)\\)?|\\+(\\(?374\\)?)\\s?(55|95))\\s?([0-9]{2}[-\\s]?){2}[0-9]{2}");
	regex passport("[A][A-Z][0-9]{7}");
	regex date("(([0-2][0-9])|(3[0-1]))[\\/\\.\\-]((0[0-9])|(1[0-2]))[\\/\\.\\-][0-2][0-9]{3}");
	string text1 = "Phone numbers people display in different ways: 094 54 54 54 or +37494545454 you can also use +(374)94 54-54-54 this form or (094)54-54-54. But it's also accepted way to use this form  (094) 54 54 54 and  +374 94 54 54 54.";
	string text = "Passport seria: AN1444442 .";
	string name_surname = "[A-Z][a-z]{3,}\\s[A-Z][a-z]{2,}(ian|yan|uni|enc|deh|toc)";
	string d = "Jane birthday is on 29.07.1998 and Jane brother's birthday is on 22-11-1995 or 31.15.2015";
	smatch cor;
	
	while(regex_search(d, cor, date)) {
		cout << cor[0] << endl;
		d = cor.suffix().str();
	}
	
	return 0;
		
}
