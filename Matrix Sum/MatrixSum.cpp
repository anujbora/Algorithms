#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 *  obtainSums() will be called only once (provided the matrix doesn't changes).
 *  sums will take O(rows*cols) space and O(rows*cols) time to set up but once
 *  set-up, it will help to get MatrixSum() in O(1) time.
 */

int rows, cols;
vector<vector<int>> sums;

void obtainSums(vector<vector<int>>& matrix)
{
    // Assumption : startRow <= endRow ; startColumn <=  endColumn
    rows = matrix.size();
    cols = matrix[0].size();
    sums = vector<vector<int>>(rows+1, vector<int>(cols+1, 0));
    for(int i=1; i<=sums.size(); i++)
    {
        for(int j=1; j<=sums[0].size(); j++)
        {
            sums[i][j] = sums[i-1][j] + sums[i][j-1] + matrix[i-1][j-1] - sums[i-1][j-1];
        }
    }
}

int MatrixSum(int startRow, int startColumn, int endRow, int endColumn) 
{
    return sums[endRow+1][endColumn+1] - sums[endRow+1][startColumn] - sums[startRow][endColumn+1] + sums[startRow][startColumn];
}