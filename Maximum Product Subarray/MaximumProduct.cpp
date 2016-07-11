#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int MaximumProduct(vector<int>& nums) 
{
    if(nums.size() == 0)
    {
        return 0;
    }

    int minSum = nums[0];
    int maxSum = nums[0];
    int sum = nums[0];

    for(int i=1; i<nums.size(); i++)
    {
        if(nums[i] >= 0)
        {
            maxSum = max(maxSum * nums[i], nums[i]);
            minSum = min(nums[i], minSum * nums[i]);
        }
        else
        {
            int temp = maxSum;
            maxSum = max(minSum * nums[i], nums[i]);
            minSum = min(nums[i], temp * nums[i]);
        }
        sum = max(sum, maxSum);
    }

    return sum;
}