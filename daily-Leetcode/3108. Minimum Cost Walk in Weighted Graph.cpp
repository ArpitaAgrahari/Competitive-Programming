#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query)
    {
        vector<int> par(n), path(n, -1);
        iota(par.begin(), par.end(), 0);

        function<int(int)> find = [&](int node)
        {
            if (par[node] != node)
            {
                par[node] = find(par[node]);
            }
            return par[node];
        };

        for (auto &it : edges)
        {
            int source = it[0], target = it[1], weight = it[2];
            int source_root = find(source);
            int target_root = find(target);

            path[target_root] &= weight;

            if (source_root != target_root)
            {
                path[target_root] &= path[source_root];
                par[source_root] = target_root;
            }
        }

        vector<int> result;
        for (auto &q : query)
        {
            int start = q[0], end = q[1];
            if (start == end)
            {
                result.push_back(0);
            }
            else if (find(start) != find(end))
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(path[find(start)]);
            }
        }
        return result;
    }
};