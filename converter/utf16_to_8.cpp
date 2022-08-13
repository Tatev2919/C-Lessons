#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bitset>
using namespace std;

int main(){
	FILE* fr = fopen("file.txt","r");
        fseek(fr,0L, SEEK_END);
	size_t s = ftell(fr); 
       	fseek(fr,0L,SEEK_SET);
	cout << s << " size is" << endl; 
  
	unsigned short m[s];

	fread(m,1,s,fr);
	fclose(fr);
	FILE* fw = fopen("res.txt","w");

	
	unsigned short res;
	unsigned int   res1;
	//unsigned short const big_endian = 0xfeff;
        //fwrite(&big_endian,2,1, fw);	
	for (int i = 1;i < s/2; ++i) {
               // cout << "2 bytes " << (unsigned short) m[i] << endl;
                
		if (m[i] >= 0 && m[i] <=127) {
			fwrite(&m[i],1,1, fw);
                	cout << "1 bytes " << (unsigned short) m[i] << endl;
        	}
        	else if(m[i] > 127 && m[i]<= 2047 ){
                	cout << "2 bytes " << (unsigned short) m[i] << endl;
			unsigned short k  =  (m[i]&0b0000000000111111);
                	unsigned short k1 =  (m[i]&0b0000011111000000)<<2;
			res = k|k1|0b1100000010000000;
                        cout << "---------------------------------------------------------" << endl;
                	cout << "2 bytes " << (unsigned short) m[i] << endl;
                	cout << "res"      << (unsigned short) res << endl;
			bitset<16> a = res;
			bitset<16>  b = m[i];
			cout << a << " res bitset" << endl;
			cout << b << " m[i] bitset" << endl;
			fwrite(&res, 2, 1 , fw);
        	} 
		else if (m[i] >2047 && m[i] <=65535 ) {
			unsigned int k  =  (m[i]&0b000000000000000000111111);
			unsigned int k1 =  (m[i]&0b000000000000111111000000)<<2;
			unsigned int k2 =  (m[i]&0b000000001111000000000000)<<4;
		        res1 = k|k1|k2|0b111000001000000010000000;
			bitset<32> a = res1;
			bitset<16> b = m[i];
                        cout << "---------------------------------------------------------" << endl;
                	cout << "3 bytes" << endl;
                	cout << "3 bytes " << (unsigned int) m[i] << endl;
                	cout << "res"      << (unsigned int) res1 << endl;
			cout << a << " res bitset" << endl;
	         	cout << b << " m[i] bitset" << endl;
			fwrite(&res1,3,1, fw);
        	} 
		//else if  (m[i] >= 240 && m[i] <= 247 ) {
		//	unsigned short k =   m[i]&0b00000000000000000000000000111111;
                //	unsigned short k1 = (m[i]&0b00000000000000000011111100000000)>>2;
                //	unsigned short k2 = (m[i]&0b00000000001111110000000000000000)>>2;
                //	unsigned short k3 = (m[i]&0b00000111000000000000000000000000)>>2;
		//	res = k|k1|k2|k3;
                //	cout << "4 bytes" << endl;
        	//}
	}
        fclose(fw);
	return 0;
}

