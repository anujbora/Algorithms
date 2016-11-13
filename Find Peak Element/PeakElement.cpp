#include <algorithm>
#include <vector>
using namespace std;

/**
 *  Time Complexity = O(log n)
 *  Space Complexity = O(1)
 */

int findPeakElement(const vector<int> &nums) 
{
    int low = 0, high = nums.size() - 1;
    
    while (low < high) 
    {
        int mid = low + (high - low) / 2;
        
        if (nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1]) 
        {
            return mid;
        }
        
        if (nums[mid] < nums[mid+1]) 
        {
            low = mid + 1;
        }
        
        else 
        {
            high = mid - 1;
        }
        
    }
    return low;
}