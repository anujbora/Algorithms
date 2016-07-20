#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 *  Time Complexity : O(n); where n is the number of elements in the array
 *  Space Complexity : O(1)
 */

bool twoSum(vector<int>& nums, int target) 
{
    int i = 0;
    int j = nums.size() - 1;

    while (i < j)
    {
        int sum = nums[i] + nums[j];

        if (sum == target)
        {
            return true;
        }

        else if (sum < target)
        {
            i++;
        }

        else
        {
            j--;
        }
    }

    return false;
}