// //left rotation
// #include<iostream>
// using namespace std;
// int main(){
//     int arr[] = {1,2,3,4,5,6,7,8,9,10};
//     int n=10;
//     int index =3;


//     //if index is too targensince arr is too small we will reduce the size(k=1000, so we wil do k=k%n);


// //1st approach :(brute force)
//  //       to divide the array in n-k element in array and left element in array and then insert it
//     //auxiliary array
//     int a[10];
//     int k=0;
//     for(int i=index;i<n;i++){
//         a[k] = arr[i];
//         k++;
//     }
//     for(int i=0;i<index;i++){
//         a[k] = arr[i];
//         k++;
//     }
//     for(int i=0;i<n;i++){
//      arr[i]=a[i];
//         cout<<a[i]<<" ";
//     }
// }




// // right rottaion
// #include<iostream>
// using namespace std;
// int main(){
//     int arr[] = {1,2,3,4,5,6,7,8,9,10};
//     int n = 10;
//     int index = 3;
//     int a[10];
//     int k = 0;
//     for(int i=n-index;i<n;i++){
//         a[k] = arr[i];
//         k++;
//     }
//     for(int i=0;i<n-index;i++){
//         a[k] = arr[i];
//         k++;
//     }
//     for(int i=0;i<n;i++){
//         arr[i]=a[i];
//         cout<<a[i]<<" ";
//     }

// }


//2nd approach :( )

// #include<iostream>
// using namespace std;
// int main(){
//     int arr[] = {1,2,3,4,5,6,7,8,9,10};
//     int n=10;
//     int r = 3;
//     r =r %n;
//     for(int i=0,j=(n-r-1);i<j;j--){
//         int t = arr[i];
//         arr[i] = arr[j];
//         arr[j] = t;
//     }
//     for(int i=n-r,j=n-1);i<j;i++,j--){
//         int t = arr[i];
//         arr[i] = arr[j];
//         arr[j] = t;
//     }
//     for(int i=0,j=(n-r-1);i<j;j--){
//         int t = arr[i];
//         arr[i] = arr[j];
//         arr[j] = t;
//     }

// }