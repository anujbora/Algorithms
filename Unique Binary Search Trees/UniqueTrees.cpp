#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int UniqueTrees(int n) 
{
    vector<int> dp(n+1, 0);

    dp[0] = dp[1] = 1;

    for (int nodes = 2; nodes <= n; nodes++)
    {
        for (int root = 1; root <= nodes; root++)
        {
            dp[nodes] = dp[nodes] + (dp[root-1] * dp[nodes - root]);
        }
    }

    return dp[n];
}