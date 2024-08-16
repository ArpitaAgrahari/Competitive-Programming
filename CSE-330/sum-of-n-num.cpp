//sum of n natural numbers using for loop
#include<iostream>
using namespace std;
int main(){             //time ccomplexity is O(n)
    int n;
    cin>>n;
    int sum = 0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    cout<<sum;
}

//sum using formual
#include<iostream>
using namespace std;
int main(){         //time ccomplexity is O(1)
    int n ;
    cin>>n;
    int sum = n*(n+1)/2;
    cout<<sum;
}
