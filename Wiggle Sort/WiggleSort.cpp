#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 *  Time Complexity : O(n); where n is the number of elements in the array
 *  Space Complexity : O(1)
 */

void WiggleSort(vector<int>& nums) 
{
    if (nums.size() < 2)
    {
        return;
    }

    for (int i = 1; i < nums.size(); i++)
    {
        if (i % 2 == 0)
        {
            if (nums[i] > nums[i-1])
            {
                swap(nums[i], nums[i-1]);
            }
        }
        else
        {
            if (nums[i] < nums[i-1])
            {
                swap(nums[i], nums[i-1]);
            }
        }
    }
}