// #include<iostream>
// using namespace std;
// int main(){
//     int arr[3][3] = {{1,2,3},{4,5,6}};
//     int m =3;
//     int n=3;
//     for(int i=0;i<m;i++){
//         for(int j=0;j<n;j++){
//             cout<<arr[i][j]<<" ";
//         }
//     }
// }


#include<iostream>
using namespace std;
int main(){
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    int arr1[r1][c1];
    int arr2[r2][c2];

    int arr3[r1][c2];
    if(c1!=r2){
        return;
    }
    for(int i=0;i<r1;i++){
        for(int j=0;i<c2;j++){
            cout<<arr3[i][j]<<" ";
        }
    }
}