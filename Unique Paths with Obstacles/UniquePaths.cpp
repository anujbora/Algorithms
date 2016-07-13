#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 *  Time Complexity : O(nm); where n is the number of rows and m is the number of columns
 *  Space Complexity : O(n)
 */

int UniquePaths(vector<vector<int>>& obstacleGrid) 
{
    int rows = obstacleGrid.size();
    int cols = obstacleGrid[0].size();
    if(obstacleGrid[0][0] == 1 || obstacleGrid[rows-1][cols-1] == 1)
    {
        return 0;
    }
    
    vector<int> pre(rows, 0);
    vector<int> cur(rows, 0);
    
    for(int i=0; i<rows; i++)
    {
        if(obstacleGrid[i][0] == 0)
        {
            pre[i] = 1;
        }
        else
        {
            break;
        }
    }
    
    for(int j=1; j<cols; j++)
    {
        if(obstacleGrid[0][j] == 0)
        {
            cur[0] = pre[0];
        }
        for(int i=1; i<rows; i++)
        {
            if(obstacleGrid[i][j] == 1)
            {
                cur[i] = 0;
            }
            else
            {
                cur[i] = cur[i-1] + pre[i];
            }
        }
        swap(pre,cur);
        fill(cur.begin(), cur.end(), 0);
    }
    return pre[rows-1];
}