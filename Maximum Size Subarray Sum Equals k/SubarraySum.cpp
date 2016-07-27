#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/**
 *  Time Comlexity : O(n); where n is the number of elements in the array
 *  Space Complexity : O(n)
 */

int SubarraySum(vector<int>& nums, int k) 
{
	int maxSize = 0;
	int sum = 0;
	unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
    	sum = sum + nums[i];
    	if (sum == k)
    	{
    		maxSize = i + 1;
    	}
    	else if (map.find(sum - k) != map.end())
    	{
    		maxSize = max(maxSize, i - map[sum - k]);
    	}

    	if (map.find(sum) == map.end())
    	{
    		map[sum] = i;
    	}
    }

    return maxSize;
}