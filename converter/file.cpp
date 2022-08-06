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
  
	unsigned char m[s];

	fread(m,1,s,fr);
	fclose(fr);
	short res;
	for (int i = 0;i < s; ++i) {
		if (m[i] >= 0 && m[i] <=127) {
			res=m[i];	
                	cout << "1 bytes" << endl;
        	}
        	if (m[i] >= 192 && m[i]<= 223 ){
			unsigned short k = m[i]&0b0000000000111111;
                	unsigned short k1 = (m[i]&0b0001111100000000)>>2;
			res = k|k1;
                	cout << "2 bytes" << endl;
        	} else if (m[i] >=224 && m[i] <=239 ) {
			unsigned short k =   m[i]&0b000000000000000000111111;
                	unsigned short k1 = (m[i]&0b000000000011111100000000)>>2;
                	unsigned short k2 = (m[i]&0b000011110000000000000000)>>2;
			res = k|k1|k2;
                	cout << "3 bytes" << endl;
        	} else if  (m[i] >= 240 && m[i] <= 247 ) {
			unsigned short k =   m[i]&0b00000000000000000000000000111111;
                	unsigned short k1 = (m[i]&0b00000000000000000011111100000000)>>2;
                	unsigned short k2 = (m[i]&0b00000000001111110000000000000000)>>2;
                	unsigned short k3 = (m[i]&0b00000111000000000000000000000000)>>2;
			res = k|k1|k2|k3;
                	cout << "4 bytes" << endl;
        	}
	}
	return 0;
}

