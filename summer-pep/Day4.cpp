// Greedy

// BUSYMAN

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> start(n), finish(n);
        for (int i = 0; i < n; i++)
        {
            cin >> start[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> finish[i];
        }

        vector<pair<int, int>> activity;
        for (int i = 0; i < n; i++)
        {
            activity.push_back({finish[i], start[i]});
        }
        sort(activity.begin(), activity.end(), [](pair<int, int> &a, pair<int, int> &b)
             {
            if(a.first==b.first) return a.second<b.second;
            return a.first<b.first; });

        int cnt = 0;
        int last = -1;
        for (int i = 0; i < n; i++)
        {
            if (activity[i].second > last)
            {
                cnt++;
                last = activity[i].first;
            }
        }
        cout << cnt << endl;
    }
}