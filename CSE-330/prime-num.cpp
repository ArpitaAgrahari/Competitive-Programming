
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
// #include <iostream>               
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//     bool flag = 0;
//     for(int i=2;i*i<=n;i++){        
//         if(n%i==0){
//             cout<<"non-prime";
//             flag = 1;
//             break;
//         }
//         }if(flag==0){
//             cout<<"prime";
//     }
//     return 0;
// }


//most efficeint approach to check prime or not
#include <iostream>                 //time complexity is O(sqrt(n))
using namespace std;

bool isPrime(int n){
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5;i*i<=n;i=i+6){
        if(n%i==0 || n%(i+2)==0){
            return false;
        }
    } 
    return true;
}
int main(){
    int n;
    cin>>n;
    if(isPrime(n)){
        cout<<"prime";
    }else{
        cout<<"non-prime";
    }
    return 0;
}