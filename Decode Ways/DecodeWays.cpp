#include <iostream>
#include <algorithm>
using namespace std;

/**
 *  Time Complexity : O(n); where n is the number of digits in the input
 *  Space Complexity : O(1)
 */

int DecodeWays(string& nums) 
{
    int r1 = 1;
    int r2 = 1;

    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == '0') 
        {
            r1 = 0;
        }
        
        if ((nums[i-1] == '1' || nums[i-1] == '2') && nums[i] <= '6')
        {
            int temp = r1;
            r1 = r1 + r2;
            r2 = r1;
        }
        else
        {
            r2 = r1;
        }
    }

    return r1;
}