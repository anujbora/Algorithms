#include <vector>
#include <algorithm>
using namespace std;

/**
 *  Time Complexity : O(m + n)
 */

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    int index1 = m - 1;
    int index2 = n - 1;
    int total_size = m + n - 1;
    
    while (index1 >= 0 && index2 >= 0)
    {
        if (nums1[index1] > nums2[index2])
        {
            nums1[total_size] = nums1[index1];
            index1--;
        }
        else
        {
            nums1[total_size] = nums2[index2];
            index2--;
        }
        total_size--;
    }
    while (index2 >= 0)
    {
        nums1[total_size] = nums2[index2];
        total_size--;
        index2--;
    }
}