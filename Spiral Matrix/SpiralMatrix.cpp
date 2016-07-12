#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

ListNode* SpiralMatrix(vector<vector<int>>& matrix) 
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
            cout << "in step 1 : " << matrix[startRow][i] << "\n";
        }
        startRow++;

        // Step 2 : Print right-most column from top to bottom
        for(int i = startRow; i <= totalRows; i++)
        {
            result.push_back(matrix[i][totalCols]);
            cout << "in step 2 : " << matrix[i][totalCols] << "\n";
        }
        totalCols--;

        // Step 3 : Print bottom-most row from right to left
        if(startRow <= totalRows)
        {
            for(int i = totalCols; i>=startCol; i--)
            {
                result.push_back(matrix[totalRows][i]);
                cout << "in step 3 : " << matrix[totalRows][i] << "\n";
            }
            totalRows--;
        }

        // Step 4 : Print left-most column from bottom to top
        if(startCol <= totalCols)
        {
            for(int i = totalRows; i>=startRow; i--)
            {
                result.push_back(matrix[i][startCol]);
                cout << "in step 4 : " << matrix[i][startCol] << "\n";
            }  
            startCol++; 
        }
    }

    return result;
}