#include <algorithm>
#include <vector>
using namespace std;

/**
 *  Time Complexity = O(n!)
 */

void generatePermutations(vector<int> nums, int begin, int size, vector<vector<int>>& result)
{
    if (begin >= (size - 1))
    {
        result.push_back(nums);
        return;
    }

    for (int i = begin; i < size; i++)
    {
        if (i > begin && nums[i] == nums[begin])
        {
            continue;
        }
        swap(nums[begin], nums[i]);
        generatePermutations(nums, begin + 1, size, result);
    }

    return;
}

vector<vector<int>> Permutations(vector<int>& nums)
{
    vector<vector<int>> result;  
    sort(nums.begin(), nums.end());  
    generatePermutations(nums, 0, nums.size(), result);
    return result;
}