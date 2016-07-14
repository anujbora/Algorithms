#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

/**
 *  Time Comlexity : O(n); where n is the number of elements in the array
 *  Space Complexity : O(1)
 */

bool RemoveDuplicates(vector<int>& nums) 
{
    if(nums.size() < 3)
    {
        return false;
    }

    int c1 = INT_MAX;
    int c2 = INT_MAX;

    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] < c1)
        {
            c1 = nums[i];
        }
        else if(nums[i] < c2)
        {
            c2 = nums[i];
        }
        else
        {
            return true;
        }
    }
    
    return false; 
}