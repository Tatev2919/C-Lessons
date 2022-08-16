#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bitset>
using namespace std;

int main(int argc, char **argv){
	FILE* fr = fopen(argv[3],"r");
        fseek(fr,0L, SEEK_END);
	size_t s = ftell(fr); 
       	fseek(fr,0L,SEEK_SET);
	cout << s << " size is" << endl; 
  
	unsigned short m[s];

	fread(m,1,s,fr);
	fclose(fr);
     	FILE* fw = fopen(argv[4],"w");
        cout << "argv1" << argv[1] << endl;  
        cout << "argv2" << argv[2] << endl;  
	
	unsigned short res = 0;
	unsigned int   res1;
	//unsigned short const big_endian = 0xfeff;
        //fwrite(&big_endian,2,1, fw);
        if (argv[1]=="utf-16" && argv[2]== "utf-8" ) {	
	        cout << "helloooooooooooooo----" << endl;
                for (int i = 1;i < s/2; ++i) {
                      // cout << "2 bytes " << (unsigned short) m[i] << endl;
                       
	       	if (m[i] >= 0 && m[i] <=127) {
                               unsigned char r = m[i];
	       		fwrite(&r,1,1, fw);
                       	cout << "1 bytes " << (unsigned short) m[i] << endl;
               	}
               	else if(m[i] > 127 && m[i]<= 2047 ){
                       	cout << "2 bytes " << (unsigned short) m[i] << endl;
	       		unsigned short k  =  ((m[i]&0b0000000000111111)|0b0000000010000000)<<8;
                       	unsigned short k1 =  (((m[i]&0b0000011111000000)<<2)|0b1100000000000000)>>8;
	       		res = k|k1;
                               
                               cout << "---------------------------------------------------------" << endl;
                       	cout << "2 bytes " << (unsigned short) m[i] << endl;
                       	cout << "res"      << (unsigned short) res << endl;
	       		bitset<16> a = res;
	       		bitset<16>  b = m[i];
	       		cout << a << " res bitset" << endl;
	       		cout << b << " m[i] bitset" << endl;
	       		fwrite(&res, 2, 1 , fw);
               	} 
               	else if(m[i] > 2047 && m[i]<= 65536 ){
	       	        unsigned int k  =  (( m[i]&0b0000000000111111)|0b0000000010000000)<<16;
                               unsigned int k1 =  (( m[i]&0b0000111111000000)|0b0010000000000000)<<2;
                               unsigned int k2 =  (((m[i]&0b1111000000000000)>>12)|0b0000000011100000);
	       		res1 = k|k1|k2;
                               cout << "---------------------------------------------------------" << endl;
                       	cout << "3 bytes " << (unsigned int) m[i] << endl;
                       	cout << "res"      << (unsigned int) res1 << endl;
	       		bitset<24> a = res1;
	       		bitset<24>  b = m[i];
	       		cout << a << " res bitset" << endl;
	       		cout << b << " m[i] bitset" << endl;
	       		fwrite(&res1, 3, 1 , fw);
                             
	       	}
	       }
              }
        fclose(fw);
	return 0;
}
