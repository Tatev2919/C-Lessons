#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bitset>
#include <regex>
using namespace std;

//Function to validate 1st and 2nd command line arguments
//As regex worked so slowly is written simple if else s 
//Args can be (utf-8 and utf-16(le|be| )), (utf-16 and utf-8) 
char validation(char** argv) {
        string a1 = argv[1];
        string a2 = argv[2];
        if (a1=="utf-8") {
              if (a2=="utf-16" || a2=="utf-16be"){ 
                    return 0;
              } else if ( a2=="utf-16le"){
                    return 1;
              }
        } else if (a1=="utf-16" && a2=="utf-8") {
              return 2;
        }
        return -1;
}

void conv_utf8_16 (size_t s, FILE* fw, unsigned char* m ) {
        unsigned short res;
	for (int i = 0;i < s; ++i) {
		if (m[i] >= 0 && m[i] <=127) {
			res=m[i];	
                	cout << "1 bytes" << endl;
			fwrite(&res,2,1, fw);
        	}
        	else if(m[i] >= 192 && m[i]<= 223 ){
			unsigned short k  =  (m[i]&0b00011111)<<6;
                	unsigned short k1 =  (m[i+1]&0b00111111);
			res = k|k1;
                	cout << "2 bytes " <<(unsigned int) m[i] << endl;
                	cout << "res"  << (unsigned int) res << endl;
			bitset<16> a = res;
			bitset<8> b = m[i];
			bitset<8> c = m[i+1];
			cout << a << " res bitset" << endl;
			cout << b << " m[i] bitset" << endl;
			cout << c << " m[i+1] bitset" << endl;
			fwrite(&res,2,1 , fw);
			++i;
        	} 
		else if (m[i] >=224 && m[i] <=239 ) {
			unsigned short k =   (m[i]&0b00001111) <<12;
                	unsigned short k1 = (m[i+1]&0b00111111)<<6;
                	unsigned short k2 = (m[i+2]&0b00111111);
			res = k|k1|k2;
			bitset<16> a = res;
			bitset<8> b = m[i];
			bitset<8> c = m[i+1];
			bitset<8> d = m[i+2];
                	cout << "3 bytes" << endl;
			cout << a << " res bitset" << endl;
			cout << b << " m[i] bitset" << endl;
			cout << c << " m[i+1] bitset" << endl;
			cout << d << " m[i+2] bitset" << endl;
			fwrite(&res,2,1, fw);
			i = i+2;
        	} 
	}


}


/*To run the converter you need pass 4 command line arguments.
        1. source file encoding
        2. destination file encoding
        3. source filename
        4. destination filename
*/
int main(int argc, char **argv){
        //Providing the correct count of arguments
        if (argc!=5) {
		cout << "Arguments count is not valid please enter correct args" << endl;
                return 0;
        } else if (validation(argv)>=0){
		cout << "arg1, arg2 are valid" << endl;	
        }
        //Opening source file for reading
	FILE* fr = fopen(argv[3],"r");
        //Counting source file content by bytes
        fseek(fr,0L, SEEK_END);
	size_t s = ftell(fr); 
       	fseek(fr,0L,SEEK_SET);
	cout << s << " size is" << endl; 
        //Adding source file content to m array
	unsigned char m[s];

	fread(m,1,s,fr);
        //Closing source file which have been opened
	fclose(fr);
        //Opening destination file
     	FILE* fw = fopen(argv[4],"w");
        string argv1 = argv[1];
        string argv2 = argv[2];
	//Providing destination file big_endian or little_endian behavior
        if (validation(argv)==0){
	        unsigned short const big_endian = 0xfffe;
                fwrite(&big_endian,2,1, fw);
                conv_utf8_16(s,fw,m); 
        } else if (validation(argv)==1) {
	        unsigned short const little_endian = 0xfeff;
                fwrite(&little_endian,2,1, fw);
                conv_utf8_16(s,fw,m); 
        }



//	unsigned short res = 0;
//	unsigned int   res1;
//	//unsigned short const big_endian = 0xfeff;
//        //fwrite(&big_endian,2,1, fw);
//        if (argv1=="utf-16" && argv2== "utf-8" ) {	
//	        cout << "helloooooooooooooo----" << endl;
//                for (int i = 1;i < s/2; ++i) {
//                      // cout << "2 bytes " << (unsigned short) m[i] << endl;
//                       
//	       	if (m[i] >= 0 && m[i] <=127) {
//                               unsigned char r = m[i];
//	       		fwrite(&r,1,1, fw);
//                       	cout << "1 bytes " << (unsigned short) m[i] << endl;
//               	}
//               	else if(m[i] > 127 && m[i]<= 2047 ){
//                       	cout << "2 bytes " << (unsigned short) m[i] << endl;
//	       		unsigned short k  =  ((m[i]&0b0000000000111111)|0b0000000010000000)<<8;
//                       	unsigned short k1 =  (((m[i]&0b0000011111000000)<<2)|0b1100000000000000)>>8;
//	       		res = k|k1;
//                               
//                               cout << "---------------------------------------------------------" << endl;
//                       	cout << "2 bytes " << (unsigned short) m[i] << endl;
//                       	cout << "res"      << (unsigned short) res << endl;
//	       		bitset<16> a = res;
//	       		bitset<16>  b = m[i];
//	       		cout << a << " res bitset" << endl;
//	       		cout << b << " m[i] bitset" << endl;
//	       		fwrite(&res, 2, 1 , fw);
//               	} 
//               	else if(m[i] > 2047 && m[i]<= 65536 ){
//	       	        unsigned int k  =  (( m[i]&0b0000000000111111)|0b0000000010000000)<<16;
//                               unsigned int k1 =  (( m[i]&0b0000111111000000)|0b0010000000000000)<<2;
//                               unsigned int k2 =  (((m[i]&0b1111000000000000)>>12)|0b0000000011100000);
//	       		res1 = k|k1|k2;
//                               cout << "---------------------------------------------------------" << endl;
//                       	cout << "3 bytes " << (unsigned int) m[i] << endl;
//                       	cout << "res"      << (unsigned int) res1 << endl;
//	       		bitset<24> a = res1;
//	       		bitset<24>  b = m[i];
//	       		cout << a << " res bitset" << endl;
//	       		cout << b << " m[i] bitset" << endl;
//	       		fwrite(&res1, 3, 1 , fw);
//                             
//	       	}
//	       }
//              }
//        fclose(fw);
	return 0;
}


