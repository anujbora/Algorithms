#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 *  Time Comlexity : O(n); where n is the number of elements in the array
 *  Space Complexity : O(1)
 */
int RemoveDuplicates(vector<int>& nums) 
{
    if(nums.size() == 0)
    {
        return 0;
    }
    int tracker = 0;
    for(int i = 1; i < nums.size(); i++)
    {
        if(nums[i] != nums[i-1])
        {
            tracker++;
            nums[tracker] = nums[i];
        }
        else
        {
            continue;
        }
    }

    return tracker + 1;  
}