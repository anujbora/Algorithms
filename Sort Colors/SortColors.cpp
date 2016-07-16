#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 *  Time Comlexity : O(n); where n is the number of elements in the array
 *  Space Complexity : O(1)
 */

void SortColors(vector<int>& nums) 
{
    if(nums.size() <= 1)
    {
        return;
    }

    int zero = -1;
    int one = -1;
    int two = -1;

    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] == 0)
        {
            two++;
            nums[two] = 2;
            one++;
            nums[one] = 1;
            zero++;
            nums[zero] = 0;
        }
        else if(nums[i] == 1)
        {
            two++;
            nums[two] = 2;
            one++;
            nums[one] = 1;
        }
        else
        {
            two++;
            nums[two] = 2;
        }
    }

    return;
}