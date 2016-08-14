#include <algorithm>
#include <vector>
using namespace std;

/**
 *  Time Complexity = O(n) where n is the number of elements in array
 *  Space Complexity = O(1)
 */

vector<int> productExceptSelf(vector<int>& nums) 
{
    int size = nums.size();
    vector<int> result(size);

    // Get products of all the numbers to the left of the number in array
    int temp = 1;
    for (int i = 0; i < size; i++)
    {
        result[i] = temp;
        temp = temp * nums[i];
    }

    temp = 1;
    for (int i = size - 1; i >=0; i--)
    {
        result[i] = result[i] * temp;
        temp = temp * nums[i];
    }

    return result;   
}