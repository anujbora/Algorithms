#include <algorithm>
#include <vector>
#include <random>
using namespace std;

class Solution 
{
public:
    Solution(vector<int> nums) 
    {
        orig = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() 
    {
        return orig;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() 
    {
        vector<int> curr = orig;
        for (int i = 1; i < curr.size(); i++)
        {
            int j = rand() % (i + 1);
            swap(curr[i], curr[j]);
        }
        return curr;
    }
    
private:
    vector<int> orig;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */