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

void input(int arr[],int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }
}
int main(){
    int r1,c1,r2,c2;
    cin>>r1>>c1>>r2>>c2;
    int arr1[r1][c1];
    int arr2[r2][c2];

    int arr3[r1][c2]={0};
    // if(c1!=r2){
    //     return 0;
    // }

    input(arr1,r1,c1);
    input(arr2,r2,c2);

    for(int i=0;i<r1;i++){
        for(int j=0;i<c2;j++){
            for(int k=0;k<c1;k++){
                arr3[i][j]=arr3[i][j]+arr1[i][k]*arr2[k][j];
            }
        }
    }
}