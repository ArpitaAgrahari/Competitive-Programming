class Solution
{
public:
    bool check(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int sec = 0;
        int maxi = intervals[0][1];
        for (auto &it : intervals)
        {
            int start = it[0], end = it[1];
            if (maxi <= start)
            {
                sec++;
            }
            maxi = max(maxi, end);
        }
        return sec >= 2;
    }

    bool checkValidCuts(int n, vector<vector<int>> &rectangles)
    {
        vector<vector<int>> x, y;
        for (auto &it : rectangles)
        {
            x.push_back({it[0], it[2]});
            y.push_back({it[1], it[3]});
        }
        return check(x) || check(y);
    }
};