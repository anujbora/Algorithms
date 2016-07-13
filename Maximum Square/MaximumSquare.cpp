#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 *  Time Complexity : O(nm); where n is number of rows and m is number of columns
 *  Space Complexity : O(n)
 */

int MaximumSquare(vector<vector<char>>& matrix) 
{
    int rows = matrix.size();
    if (rows == 0) 
    {
        return 0;
    }
    int cols = matrix[0].size();

    vector<int> pre(rows, 0);
    vector<int> cur(rows, 0);

    int maxSide = 0;

    for (int i = 0; i < rows; i++) 
    {
        pre[i] = matrix[i][0] - '0';
        maxSide = max(maxSide, pre[i]);
    }
    
    for (int j = 1; j < cols; j++) 
    {
        cur[0] = matrix[0][j] - '0';
        maxSide = max(maxSide, cur[0]);
        for (int i = 1; i < rows; i++) 
        {
            if (matrix[i][j] == '1') 
            {
                cur[i] = min(cur[i-1], min(pre[i], pre[i-1])) + 1;
                maxSide = max(maxSide, cur[i]);
            }
        }
        swap(pre, cur);
        fill(cur.begin(), cur.end(), 0);
    }
    return maxSide * maxSide;
}