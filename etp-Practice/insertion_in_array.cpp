//Array:

// #include<iostream>
// using namespace std;
// void insert(int arr[],int n,int pos,int val){
//     for(int i=n;i>pos;i--){
//         arr[i]=arr[i-1];
//     }
//     arr[pos]=val;
//     n++;
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
    
// }
// int main(){
//     int n;
//     cin >>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int pos;
//     int val;
//     cin>>pos>>val;
//     insert(arr,n,pos,val);
//     return 0;
// }




// #include<iostream>
// using namespace std;
// void deletion(int arr[],int n,int pos){
//     for(int i=pos;i<n-1;i++){
//         arr[i]=arr[i+1];
//     }
//     n--;
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
// }
// int main(){
//     int n;
//     cin>>n;
//     int arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }
//     int pos;
//     cin>>pos;
//     deletion(arr,n,pos);
// }



// #include<iostream>
// using namespace std;
// void multiply(int arr1[][100], int arr2[][100], int temp[][100], int n, int m, int p) {
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < p; j++) {
//             temp[i][j] = 0;
//             for (int k = 0; k < m; k++) {
//                 temp[i][j] += arr1[i][k] * arr2[k][j];
//             }
//         }
//     }
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < p; j++) {
//             cout << temp[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// int main() {
//     int n, m, p;
//     cin >> n >> m >> p;
//     int arr1[100][100];
//     int temp[100][100];
//     int arr2[100][100];
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             cin >> arr1[i][j];
//         }
//     }
//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < p; j++) {
//             cin >> arr2[i][j];
//         }
//     }
//     multiply(arr1, arr2, temp, n, m, p);
// }




//stack using array
// #include<iostream>
// #include<stack>
// using namespace std;
// int main(){
//     stack<int> s;
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     cout<<s.top()<<endl;
//     s.pop();
//     cout<<s.top()<<endl;
//     cout<<s.size()<<endl;
//     cout<<s.empty()<<endl;
//     return 0;
// }


//user defined input for stack implementaion using array
// #include<iostream>
// #include<stack>
// using namespace std;

// int main(){
//     //stack input from user 
//     stack<int> s;
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         int x;
//         cin>>x;
//         s.push(x);
//     }
//     for(int i=0;i<n;i++){
//         cout<<s.top()<<endl;
//         s.pop();
//     }
//     // cout<<s.top()<<endl;
//     // s.pop();
//     // cout<<s.top()<<endl;
//     // cout<<s.size()<<endl;
//     // cout<<s.empty()<<endl;
//     return 0;
// }




//queue using aaray

#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<int> q;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        q.push(x);
    }
    for(int i=0;i<n;i++){
        cout<<q.front()<<" ";
        q.pop();
    }
    queue<int> q1;
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        q1.push(q.back());
        q.back()--;
    }
    for(int i=0;i<m;i++){
        cout<<q1.front()<<" ";
        q1.pop();
    }
    return 0;

}