//fermat's factoring method  : used to factorize a composite number into its prime factors
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a = sqrt(n);
    int b = a*a - n;
    while(sqrt(b)!=int(sqrt(b))){
        a++;
        b = a*a - n;
    }
    cout<<a-sqrt(b);
    return 0;
}