//fermat little theorem to check prime or not
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int a;
    cout<<"Enter the value of a: ";
    cin>>a;
    if((a^(n-1))%n==1){
        cout<<n<<" is a prime number."<<endl;
    }
    else{
        cout<<n<<" is not a prime number."<<endl;
    }
    return 0;
}