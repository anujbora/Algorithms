#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 *	Running Time : O(n^2); where n is the number of elements in the input
 *	Space Complexity : O(1)
 */

int Battleships(vector<vector<char>>& board) 
{
	int count = 0;

	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[0].size(); j++)
		{
			if (board[i][j] == '.')
			{
				continue;
			}
			else if (i > 0 && board[i - 1][j] == 'X')
			{
				continue;
			}
			else if (j > 0 && board[i][j - 1] == 'X')
			{
				continue;
			}
			else
			{
				count++;
			}
		}
	}

	return count;
}