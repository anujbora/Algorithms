#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 *  Time Complexity : O(n^2) where n is the number of elements in the array
 *  Space Complexity : O(1)
 */

int threeSumClosest(vector<int>& nums, int target) 
{
    int diff = INT_MAX;
    int result;
    sort(nums.begin(), nums.end());
    
    for (int i = 0; i < nums.size(); i++)
    {
        int front = i + 1;
        int back = nums.size() - 1;
        
        while (front < back)
        {
            int sum = nums[i] + nums[front] + nums[back];
            
            if (abs(sum - target) < diff)
            {
                diff = abs(sum - target);
                result = sum;
            }
            
            if (sum > target)
            {
                back--;
            }
            else
            {
                front++;
            }
        }
    }
    
    return result;
}