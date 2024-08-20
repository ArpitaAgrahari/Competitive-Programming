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

//sum using formuala
#include<iostream>
using namespace std;
int main(){         //time ccomplexity is O(1)
    int n ;
    cin>>n;
    int sum = n*(n+1)/2;
    cout<<sum;
}

//best approach is using formula because it is constant time complexity


//array of strings and soreted the each string and then sorted the whole array what is runtime of algorithm
//time complexity is O(n*mlogm+nlogn) where n is the number of strings and m is the length of the string
//hpw? because we are sorting each string and then sorting the whole array



