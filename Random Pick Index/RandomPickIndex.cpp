#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

/**
 *  Set-up Complexity : O(n); where n is the number of elements in the array
 *  Getting random Index Complexity : O(1)
 *  Space Complexity : O(n)
 */

class Solution 
{
public:
    Solution(vector<int> nums) 
    {
        for (int i = 0; i < nums.size(); i++) 
        {
            indices[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) 
    {
        int index = rand() % (indices[target].size());
        return indices[target][index];
    }

private:
    unordered_map<int, vector<int>> indices;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */