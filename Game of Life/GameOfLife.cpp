#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 *      [2nd bit, 1st bit] = [next state, current state]
 *
 *      - 00  dead (next) <- dead (current)
 *      - 01  dead (next) <- live (current)  
 *      - 10  live (next) <- dead (current)  
 *      - 11  live (next) <- live (current) 
 *
 *      by @yavinci (https://discuss.leetcode.com/user/yavinci)
 */

/**
 *      Time COmplexity : O(nm)
 *      Space Complexity : O(1)
 */ 

int getAliveNeighbours(vector<vector<int>>& board, int row, int column)
{
    int count = 0;
    int totalRows = board.size();
    int totalColumns = board[0].size();

    for (int i = row - 1; i <= row + 1; i++)
    {
        for (int j = column - 1; j <= column + 1; j++)
        {
            if (i < 0 || j < 0 || i >= totalRows || j >= totalColumns)
            {
                continue;
            }
            else
            {
                count = count + (board[i][j] & 1);
            }
        }
    }

    count = count - (board[row][column] & 1);

    return count;
}

vector<vector<int>> largestNumber(vector<vector<int>>& board) 
{
    if (board.size() == 0)
    {
        return board;
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            int aliveNeigbours = getAliveNeighbours(board, i, j);

            if(board[i][j] == 1 && aliveNeigbours >= 2 && aliveNeigbours <= 3) 
            {  
                board[i][j] = 3;
            }

            if(board[i][j] == 0 && aliveNeigbours == 3) 
            {
                board[i][j] = 2;
            }
        }
    }

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            board[i][j] = (board[i][j] >> 1);
        }
    }
    return board;
}