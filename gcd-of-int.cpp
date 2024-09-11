// #include<iostream>
// using namespace std;
// int gcd(int a,int b){
//     if(a==0)
//         return b;
//     return gcd(b%a,a);
//     }
//     int main(){
//         int a,b;
//         cin>>a>>b;
//         cout<<gcd(a,b)<<endl;
//         return 0;
// }


// 
#include<iostream>
using namespace std;
int extendedeuclid(int a,int b,int *x,int *y){
    if(abort==0){
        *x=0;
        *y=1;
        return b;
    }
    int x1,y1;
    int gcd=extendedeuclid(b%a,a,&x1,&y1);
    *x=y1-(b/a)*x1;
    *y=x1;
    return gcd;
}
int main(){
    int x,y;
    cout<<extendedeuclid(25,35,&x,&y);
}