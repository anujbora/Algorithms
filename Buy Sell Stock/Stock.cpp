#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MaximumStockProfit(vector<int>& prices) 
{
    if(prices.size() == 0)
    {
        return 0;
    }

    int curSum = 0;
    int maxSum = 0;
    int buy = 0;
    int sell = 0;

    for(int i=1; i<prices.size(); i++)
    {
        if(prices[i] < prices[buy])
        {
            buy = i;
        }

        curSum = prices[i] - prices[buy];
        maxSum = max(curSum, maxSum);
    }

    return maxSum;
}