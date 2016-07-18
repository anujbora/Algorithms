#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*  Solution #1
 *
 *  Time Complexity : O(n); where n is the number of days
 *  Space Complexity : O(n)
 */

int MaximumStockProfit(vector<int>& prices) 
{
    if(prices.size() < 2)
    {
        return 0;
    }

    int n = prices.size();

    vector<int> buy(n, 0);
    vector<int> sell(n, 0);
    vector<int> rest(n, 0);

    buy[0] = -prices[0];
    sell[0] = 0;
    rest[0] = 0;

    for (int i = 1; i < n; i++)
    {
        buy[i] = min(buy[i-1], rest[i-1] - prices[i]);
        sell[i] = min(sell[i-1], buy[i-1] + prices[i]);
        rest[i] = min(rest[i-1], sell[i-1]);
    }

    return max(sell[n-1], rest[n-1]);
}

/*  Solution #2 [OPTIMAL]
 *
 *  Time Complexity : O(n); where n is the number of days
 *  Space Complexity : O(1)
 */

 int MaximumStockProfitOptimal(vector<int>& prices) 
 {
    if(prices.size() < 2)
    {
        return 0;
    }

    int n = prices.size();

    int sell = 0;
    int buy = -prices[0];
    int rest = 0;

    for (int i = 1; i < n; i++)
    {
        int temp_sell = sell;
        sell = max(buy + prices[i], sell);
        buy = max(buy, rest - prices[i]);
        rest = max(rest, temp_sell);
    }

    return max(sell, rest);
 }
