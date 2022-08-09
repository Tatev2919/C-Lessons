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
  
	unsigned char m[s];

	fread(m,1,s,fr);
	fclose(fr);
	FILE* fw = fopen("res.txt","w");

	
	unsigned short res_2 = 0b1100000010000000;
	unsigned int   res_3;
	//unsigned short const big_endian = 0xfeff;
        //fwrite(&big_endian,2,1, fw);	
	for (int i = 2;i < s; i+=2) {
		if (m[i] >= 0 && m[i] <=127) {
                	cout << "1 bytes" << endl;
			fwrite(&m[i],2,1, fw);
        	}
        	else if(m[i] > 127 && m[i]<= 2047 ){
			unsigned short k   =  (m[i]&0b00111111);
			unsigned short k1  =  (m[i]&0b11000000)<<2;
                        unsigned short k2  = 0;
			if (m[i] > 255 ) {
                                cout << "world " << endl;
				k2  =  (m[i+1]&0b00000111)<<9;
			        res_2 = res_2|k|k1|k2;
			} else {
                                cout << "Hello there "<< endl;
                        	res_2 = k|k1|0b1100000010000000;
                        }
                	cout << "2 bytes "  << (unsigned int) m[i]<< endl;
                	//cout << "res"  << (unsigned int) res << endl;
			bitset<16> a = res_2;
			bitset<16> in1 = k;
			bitset<16>  in2= k1;
			bitset<16>  in3= k2;
			bitset<8> b = m[i];
			bitset<8> c = m[i+1];
			cout << a << " res_2 bitset" << endl;
			cout << b << " m[i] bitset" << endl;
			cout << c << " m[i+1] bitset" << endl;
			cout << in1 << " k bitset" << endl;
			cout << in2 << " k1 bitset" << endl;
			cout << in3 << " k2 bitset" << endl;
			fwrite(&res_2,2,1 , fw);
        	} 
		//else if (m[i] >=224 && m[i] <=239 ) {
		//	unsigned short k =   (m[i]&0b00001111) <<12;
                //	unsigned short k1 = (m[i+1]&0b00111111)<<6;
                //	unsigned short k2 = (m[i+2]&0b00111111);
		//	res = k|k1|k2;
		//	bitset<16> a = res;
		//	bitset<8> b = m[i];
		//	bitset<8> c = m[i+1];
		//	bitset<8> d = m[i+2];
                //	cout << "3 bytes" << endl;
		//	cout << a << " res bitset" << endl;
		//	cout << b << " m[i] bitset" << endl;
		//	cout << c << " m[i+1] bitset" << endl;
		//	cout << d << " m[i+2] bitset" << endl;
		//	fwrite(&res,2,1, fw);
		//	i = i+2;
        	//} 
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

