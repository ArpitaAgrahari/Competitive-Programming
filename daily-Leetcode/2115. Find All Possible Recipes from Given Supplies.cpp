#include <iostream>
using namespace std;
class Solution
{
public:
    vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
    {
        unordered_set<string> st(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> mp;
        unordered_map<string, int> visited;
        vector<string> res;

        for (size_t i = 0; i < recipes.size(); i++)
        {
            mp[recipes[i]] = ingredients[i];
        }
        function<bool(string)> check = [&](string recipe)
        {
            if (visited.count(recipe))
            {
                return visited[recipe] == 1;
            }
            if (st.count(recipe))
            {
                return true;
            }

            if (!mp.count(recipe))
            {
                return false;
            }
            visited[recipe] = 0;
            for (const string &ingredient : mp[recipe])
            {
                if (!check(ingredient))
                {
                    visited[recipe] = -1;
                    return false;
                }
            }

            visited[recipe] = 1;
            res.push_back(recipe);
            return true;
        };

        for (const string &recipe : recipes)
        {
            check(recipe);
        }

        return res;
    }
};