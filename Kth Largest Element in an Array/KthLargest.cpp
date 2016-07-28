#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 *  Time Complexity : Average Case : O(n)
 *                    Best Case : O(n)
 *                    Worst Case : O(n^2);
 *                    where n is the number of elements in the array
 *  Space Complexity : O(1)
 *  Worst case happens when array is already sorted in descending order.
 *  As we are chosing last element as pivot, the next iteration size will
 *  always decrease by only 1. And if k = 1; its complexity will be O(n^2).
 */

int partition(vector<int>& nums, int start, int end)
{
    int i = start - 1;
    int j = start;
    int pivot = nums[end];
    
    while (j < end)
    {
        if (nums[j] >= pivot)
        {
            i++;
            swap(nums[j], nums[i]);   
        }
        j++;
    }
    swap(nums[end], nums[i+1]);
    return (i + 1);
}

int KthLargest(vector<int>& nums, int& k) 
{
    int start = 0;
    int end = nums.size() - 1;
    
    while (true)
    {
        int pivot = partition(nums, start, end);

        if (pivot == (k - 1))
        {
            return nums[k];
        }
        else if (pivot < (k - 1))
        {
            start = pivot + 1;
        }
        else
        {
            end = pivot - 1;
        }
    }
}