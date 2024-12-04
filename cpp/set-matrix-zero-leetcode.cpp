//set matrix zero 
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int matrix[3][3] = {{1,2,3},{4,0,6},{7,8,9}};
    int row = 3;
    int col = 3;
    bool firstRowZero = false;
    bool firstColZero = false;
    for(int i=0;i<row;i++){
        if(matrix[i][0] == 0){
            firstColZero = true;
            break;
        }
    }
    for(int i=0;i<col;i++){
        if(matrix[0][i] == 0){
            firstRowZero = true;
            break;
        }
    }
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(matrix[i][j] == 0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }
    if(firstRowZero){
        for(int i=0;i<col;i++){
            matrix[0][i] = 0;
        }
    }
    if(firstColZero){
        for(int i=0;i<row;i++){
            matrix[i][0] = 0;
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
}