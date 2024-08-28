//fermat's factoring method  : used to factorize a composite number into its prime factors
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n<=0){
        cout<<"Invalid input";
        return 0;
    }
    int a = ceil(sqrt(n));
    int b2 = a*a - n;
    while(sqrt(b2) != int(sqrt(b2))){
        a++;
        b2 = a*a - n;
    }
    int b = sqrt(b2);
    int factor1 = a+b;
    int factor2 = a-b;
    cout<<factor1<<" "<<factor2;
    return 0;
}