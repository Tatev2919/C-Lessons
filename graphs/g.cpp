#include <iostream>
using namespace std;

int main() {
	int** x = new int*[9];
        
        for(int i = 0; i < 9; i++){
        	x[i] = new int[9];
                for(int j = 0; j < 9; j++){
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
        x[6][1] = 1;
        x[7][4] = 1;
        x[7][6] = 1;
        x[7][0] = 1;
        x[8][4] = 1;
        x[8][1] = 1;
        x[1][6] = 1;
        x[1][8] = 1;
        x[1][0] = 1;
        x[0][7] = 1;
        x[0][1] = 1;
        
        string names [9] = {"Yerevan","Ashtarak","Gyumri","Artashat","Yeghvard","Talin", "Aparan", "Abovyan","Oshakan"}; 
        for(int i = 0; i < 9; i++){
                cout << i << ": ";
                for(int j = 0; j < 9; j++){
                	cout << x[i][j] << "  ";
                } 
                cout << endl;
	}
        for(int i = 0; i < 9; i++){
                cout << names[i] << " ---- > " << endl; 
                for(int j = 0; j < 9; j++){
                        if (x[i][j]==1) {
                	     cout << names[j]<<endl;
                        }
                } 
                cout << endl;
	}
        
        
        for(int i = 0; i < 9; i++){
                cout << i <<" : " << names[i] << endl;
        }
	return 0;
}
