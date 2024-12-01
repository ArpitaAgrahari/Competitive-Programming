#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> ids(n),costs(n);
    for (int i=0;i<n;i++)
        cin>>ids[i];
    for (int i=0;i<n;i++)
        cin>>costs[i];

    int bud;
    cin >> bud;
    int c = 0, d = 0;

    for (int i = 0; i < n; i++)
    {
        int buyCost = costs[i];
        int Quantity = (buyCost != 0) ? bud / buyCost : 0;
        if (Quantity > 0)
        {
            int a = 0;
            int b = 0;

            for (int j = 0; j < n; j++)
            {
                if (i != j && ids[i] % ids[j] == 0)
                {
                    a += Quantity;
                    b += costs[j] * Quantity;
                }
            }
            if (a > c ||
                (a == c && b > d))
            {
                c = a;
                d = b;
            }
        }
    }
    cout << c << " " << d << endl;
    return 0;
}
