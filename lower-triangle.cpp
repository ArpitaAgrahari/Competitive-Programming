
//lower triangle in matrix
// #include<iostream>
// using namespace std;
// int main(){
//     int arr[][3] = {{1,2,3},{4,5,6},{7,8,9}};
//     for(int i=0;i<3;i++){
//         for(int j=0;j<3;j++){
//             if(i<=j){
//                 arr[i][j]=0;
//             }
//         }
//     }
//     for(int i=0;i<3;i++){
//         for(int j=0;j<3;j++){
//             cout<<arr[i][j]<<" ";
//             cout<<endl;
//         }
//     }
// }


//finding the peak element
// #include<iostream>
// using namespace std;
// int main(){
//     int arr[]={12,10,5,7,6,2};
//     int n = 6;
//      if(arr[0]>arr[1]){
//             cout<<arr[0]<<" ";
//         }else{
//     for(int i=0;i<n;i++){
       
//         if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
//             cout<<arr[i]<<" ";
//         }
//     }
//     }
// }


//finding peak using binary search
// #include<iostream>
// using namespace std;

// int main() {
//     int arr[] = {12, 10, 5, 7, 6, 2};
//     int n = 6;
//     int s = 0, e = n - 1;

//     while (s <= e) {
//         int mid = s + (e - s) / 2;
//         if (mid > 0 && arr[mid] < arr[mid - 1]) {
//             e = mid - 1;
//         } else {
//             s = mid + 1;
//         }
//     }

//     cout << "The index of the smallest element is: " << s << endl;
//     return 0;
}