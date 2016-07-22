#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 *  Time Complexity : O(nm); where n is the target value and m is the number of available
 *                    coin denominations
 *  Space Complexity : O(n)
 */

int CoinChange(vector<int>& coins, int target) 
{
    vector<int> dp(target+1, target+1);

    dp[0] = 0;

    for (int i = 1; i <= target; i++)
    {
        for (int j = 0; j < coins.size(); j++)
        {
            if (coins[j] <= i)
            {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    if (dp[target] > target)
    {
        return -1;
    }

    return dp[target];
}