#include <algorithm>
#include <vector>
using namespace std;

/**
 *  Time Complexity = O(log n)
 */

int search(vector<int>& nums, int target) 
{
    int low = 0;
    int high = nums.size() - 1;
        
    while (low <= high)
    {
        int mid = low + (high-low) / 2;
        
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] > target)
        {
            if(nums[low] <=target || nums[mid] < nums[low])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (nums[low] > target || nums[mid] >= nums[low])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    
    return -1;  
}