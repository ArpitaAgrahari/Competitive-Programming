
//naive approach to check prime or not 

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cin>>n;
//     bool flag = 0;
//     for(int i=2;i<n;i++){
//         if(n%i==0){
//             cout<<"Non-prime";
//             flag = 1;
//             break;
//         }
//         }if(flag==0){
//             cout<<"Prime";
//         }
//     return 0;
// }

//efficent approach to check prime using square root of n
#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    bool flag = 0;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            cout<<"Non-prime";
            flag = 1;
            break;
        }
        }if(flag==0){
            cout<<"Prime";
    }
    return 0;
}
