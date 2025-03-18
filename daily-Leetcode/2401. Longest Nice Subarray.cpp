class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int maxi = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            int curr = 0;
            for (int j = i; j < nums.size(); j++)
            {
                if ((curr & nums[j]) == 0)
                {
                    curr |= nums[j];
                    maxi = max(maxi, j - i + 1);
                }
                else
                    break;
            }
        }
        return maxi;
    }
};