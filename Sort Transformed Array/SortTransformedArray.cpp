#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 *  Time Comlexity : O(n); where n is the number of elements in the array
 */

int quad(int x, int a, int b, int c) 
{
    return (a * x * x) + (b * x) + c;
}

vector<int> SortTransformedArray(vector<int>& nums, int a, int b, int c) 
{
    int n = nums.size();
    vector<int> sorted(n);
    int i = 0, j = n - 1;
    
    int index = 0;
    
    if (a >= 0)
    {
        int index = n - 1;
    }
    
    while (i <= j) 
    {
        if (a >= 0) 
        {
            int num1 = quad(nums[i], a, b, c);
            int num2 = quad(nums[j], a, b, c);

            if (num1 > num2)
            {
                sorted[index] = num1;
                i++;
            }
            else
            {
                sorted[index] = num2;
                j--;
            }

            index--;  
        } 
        else 
        {
            int num1 = quad(nums[i], a, b, c);
            int num2 = quad(nums[j], a, b, c);

            if (num1 > num2)
            {
                sorted[index] = num2;
                j--;
            }
            else
            {
                sorted[index] = num1;
                i++;
            }

            index++; 
        }  
    }

    return sorted;
}