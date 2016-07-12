#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> SpiralMatrix(vector<vector<int>>& matrix) 
{
    vector<int> result;

    if(matrix.size() == 0)
    {
        return result;
    }

    int totalRows = matrix.size() - 1;
    int totalCols = matrix[0].size() - 1;
    int startRow = 0;
    int startCol = 0;

    while(startRow <= totalRows && startCol <= totalCols)
    {
        // Step 1 : Print top-most row from left to right
        for(int i = startCol; i <= totalCols; i++)
        {
            result.push_back(matrix[startRow][i]);
        }
        startRow++;

        // Step 2 : Print right-most column from top to bottom
        for(int i = startRow; i <= totalRows; i++)
        {
            result.push_back(matrix[i][totalCols]);
        }
        totalCols--;

        // Step 3 : Print bottom-most row from right to left
        if(startRow <= totalRows)
        {
            for(int i = totalCols; i>=startCol; i--)
            {
                result.push_back(matrix[totalRows][i]);
            }
            totalRows--;
        }

        // Step 4 : Print left-most column from bottom to top
        if(startCol <= totalCols)
        {
            for(int i = totalRows; i>=startRow; i--)
            {
                result.push_back(matrix[i][startCol]);
            }  
            startCol++; 
        }
    }

    return result;
}