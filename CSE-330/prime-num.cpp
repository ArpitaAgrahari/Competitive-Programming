
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
    for(int i=2;i*i<=n;i++){        //i*i<=n is the condition how is it working?
                                    //because if n is not prime then it will have atleast one factor less than or equal to square root of n
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
