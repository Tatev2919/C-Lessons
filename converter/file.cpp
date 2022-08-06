#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){
	FILE* fr = fopen("file.txt","r");
        fseek(fr,0L, SEEK_END);
	size_t s = ftell(fr); 
       	fseek(fr,0L,SEEK_SET);
	cout << s << " size is" << endl; 
  
	char m[s];

	fread(m,1,s,fr);
	fclose(fr);

	for (int i = 0;i < s; ++i) {
		cout << m[i] << endl;
	}
	return 0;
}

