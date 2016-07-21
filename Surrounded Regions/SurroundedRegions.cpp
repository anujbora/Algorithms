#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void dfs(vector<vector<char>>& matrix, int i, int j, int rows, int cols)
{
    if (i < 0 || i >= rows)
    {
        return;
    }

    if (j < 0 || i >= cols)
    {
        return;
    }

    if (matrix[i][j] == '0')
    {
        matrix[i][0] = 'C';
        dfs(matrix, i-1, j, rows, cols);
        dfs(matrix, i, j-1, rows, cols);
        dfs(matrix, i+1, j, rows, cols);
        dfs(matrix, i, j+1, rows, cols);
    }

    return;  
}

void SurroundedRegions(vector<vector<char>>& matrix) 
{
    int rows = matrix.size();
    if (rows == 0) 
    {
        return;
    }
    int cols = matrix[0].size();

    for (int i = 0; i < rows; i++) 
    {
        if (matrix[i][0] == '0')
        {
            dfs(matrix, i, 0, rows, cols);
        }
        if (cols > 1)
        {
            if (matrix[i][cols-1] == '0')
            {
                dfs(matrix, i, cols-1, rows, cols);
            }
        }
    }

    for (int i = 0; i < cols; i++) 
    {
        if (matrix[0][i] == '0')
        {
            dfs(matrix, 0, i, rows, cols);
        }
        if (rows > 1)
        {
            if (matrix[rows-1][i] == '0')
            {
                dfs(matrix, rows-1, i, rows, cols);
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; i < cols; j++)
        {
            if (matrix[i][j] == 'O')
            {
                matrix[i][j] = 'X';
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; i < cols; j++)
        {
            if (matrix[i][j] == 'C')
            {
                matrix[i][j] = 'O';
            }
        }
    }
}