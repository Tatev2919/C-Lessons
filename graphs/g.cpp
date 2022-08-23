#include <iostream>
using namespace std;

int main() {
	int** x = new int*[11];
        
        for(int i = 2; i < 11; i++){
        	x[i] = new int[11];
                for(int j = 0; j < 11; j++){
                	x[i][j] = 0;
                }
	}
        x[2][3] = 1;
        x[2][5] = 1;
        x[3][2] = 1;
        x[3][4] = 1;
        x[3][6] = 1;
        x[4][3] = 1;
        x[4][7] = 1;
        x[5][2] = 1;
        x[5][6] = 1;
        x[5][8] = 1;
        x[6][3] = 1;
        x[6][5] = 1;
        x[6][7] = 1;
        x[6][9] = 1;
        x[7][4] = 1;
        x[7][6] = 1;
        x[7][10] = 1;
        x[8][4] = 1;
        x[8][9] = 1;
        x[9][6] = 1;
        x[9][8] = 1;
        x[9][10] = 1;
        x[10][7] = 1;
        x[10][9] = 1;
        
        for(int i = 2; i < 11; i++){
                for(int j = 2; j < 11; j++){
                	cout << x[i][j] << "  ";
                } 
                cout << endl;
	}
        
        string names [11] = {"-","-","Gyumri","Artashat","Yeghvard","Talin", "Aparan", "Abovyan","Oshakan","Ashtarak", "Yerevan"}; 
        
        for(int i = 2; i < 11; i++){
                cout << i <<" : " << names[i] << endl;
        }
	return 0;
}
