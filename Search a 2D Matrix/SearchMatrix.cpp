#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 *  Time Complexity : O(log n); where n is the number of elements in matrix
 *  Space Complexity : O(1)
 */

bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    if (matrix.empty() || matrix[0].empty())
    {
        return false;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();
    int start = 0;
    int end = (rows * cols) - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        
        if (matrix[mid/cols][mid%cols] == target)
        {
            return true;
        }
        
        else if (matrix[mid/cols][mid%cols] < target)
        {
            start = mid + 1;
        }
        
        else
        {
            end = mid - 1;
        }
    }

    return false;
}