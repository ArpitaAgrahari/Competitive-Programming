// Practice Problems
// check Prime or not
#include <bits/stdc++.h>
using namespace std;

int check_prime(int n)
{
    if (n <= 1)
        return 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int n;
    cin >> n;
    if (check_prime(n))
        cout << "Prime" << endl;
    else
        cout << "Not Prime" << endl;
}
