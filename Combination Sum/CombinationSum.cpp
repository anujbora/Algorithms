#include <algorithm>
#include <vector>
using namespace std;

/**
 *  Time Complexity = O((n+k)!) where n is the number of elements in the array
 *                    and k is the maximum frequency of repeated element
 */

void dfs(vector<int>& candidates, vector<int>& set, vector<vector<int>>& res, int target, int begin)
{
    if (target == 0)
    {
        res.push_back(set);
        return;
    }
    
    for (int i = begin; i < candidates.size(); i++)
    {
        if (target < candidates[i])
        {
            return;
        }
        set.push_back(candidates[i]);
        dfs(candidates, set, res, target - candidates[i], i);
        set.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
{
    sort(candidates.begin(), candidates.end());

    vector<int> set;
    vector<vector<int>> res;
    
    dfs(candidates, set, res, target, 0);
    
    return res;
}