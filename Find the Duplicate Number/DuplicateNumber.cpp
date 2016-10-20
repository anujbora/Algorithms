#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int getCount(vector<int>& nums, int& mid)
{
    int count = 0;
    for (int n : nums)
    {
        if (n <= mid)
        {
            count++;
        }
    }
    return count;
}

int findDuplicate(vector<int>& nums) 
{
    int low = 0;
    int high = nums.size() - 1;
    
    while (low < high)
    {
        int mid = low + ((high - low) / 2);
        
        int count = getCount(nums, mid);
        
        if (count > mid)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    
    return low;
}