#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 *  Time Comlexity : O(n); where n is the number of elements in the array
 *  Space Complexity : O(1)
 */

int RemoveDuplicates(vector<int>& nums, int k) 
{
    if(nums.size() == 0)
    {
        return 0;
    }

    int tracker = 0;
    int count = 1;

    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] != nums[i-1])
        {
            tracker++;
            nums[tracker] = nums[i];
            count = 1;
        }
        else
        {
            if(count < k)
            {
                tracker++;
                nums[tracker] = nums[i];
                count++;
            }
        }
    }

    return tracker + 1; 
}