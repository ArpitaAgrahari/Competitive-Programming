class Solution
{
public:
    void dfs(int i, int col, vector<vector<int>> &sameCol, vector<vector<int>> &adj, vector<int> &vis)
    {
        vis[i] = 1;
        sameCol[col].push_back(i);
        for (auto it : adj[i])
        {
            if (!vis[it])
                dfs(it, col, sameCol, adj, vis);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>> &edges)
    {
        int m = edges.size();
        vector<vector<int>> adj(n), sameCol(n);
        for (int i = 0; i < m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int col = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(i, col, sameCol, adj, vis);
                col++;
            }
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (sameCol[i].empty())
                continue;
            int currSize = sameCol[i].size() - 1;
            bool ok = true;
            for (auto it : sameCol[i])
            {
                if (adj[it].size() != currSize)
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
                cnt++;
        }
        return cnt;
    }
};