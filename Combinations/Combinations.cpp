#include <algorithm>
#include <vector>
using namespace std;

/**
 *  Time Complexity = O(n choose k)
 */

void dfs(vector<vector<int>>& result, vector<int>& sol, int start, int end, int curr_size, int k)
{
    if (curr_size == k)
    {
        result.push_back(sol);
        return;
    }

    for (int i = start; i <= end; i++)
    {
        sol.push_back(i);
        dfs(result, sol, i + 1, end, curr_size + 1, k);
        sol.pop_back();
    }
}

vector<vector<int>> Combinations(int n, int k) 
{
    vector<vector<int>> result;

    if (n < k)
    {
        return result;
    }

    vector<int> sol; 
    dfs(result, sol, 1, n, 0, k);

    return result; 
}