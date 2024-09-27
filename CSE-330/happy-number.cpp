//given a positive integer n, determine if it is a happy number.
// A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
#include <iostream>
#include <unordered_set>
using namespace std;
bool isHappy(int n) {
    unordered_set<int> s;
    while(n!=1) {
        if(s.find(n)!=s.end()) return false;
        s.insert(n);
        int sum=0;
        while(n) {
            sum+=(n%10)*(n%10);
            n/=10;
        }
        n=sum;
    }
    return true;
}
int main() {
    int n;
    cin>>n;
    cout<<isHappy(n);
    return 0;
}
