
//spiral 2 d array formation
#include <iostream>
#include<vector>
using namespace std;

void print_spiral(vector<vector<int>> &v,int r,int c){
    int top = 0, bottom = r-1, left = 0, right = c-1;
    while(top<=bottom && left<=right){
        for(int i=left;i<=right;i++){
            cout<<v[top][i]<<" ";
        }
        top++;
        for(int i=top;i<=bottom;i++){
            cout<<v[i][right]<<" ";
        }
        right--;
        if(top<=bottom){
            for(int i=right;i>=left;i--){
                cout<<v[bottom][i]<<" ";
            }
            bottom--;
        }
        if(left<=right){
            for(int i=bottom;i>=top;i--){
                cout<<v[i][left]<<" ";
            }
            left++;
        }
    }

}

int main() {
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int r = 3, c = 3;
    print_spiral(arr, r, c);
    
    return 0;
}