#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 *	Running Time : O(n); where n is the number of elements in the input
 *	Space Complexity : O(n)
 */

int ArithmeticSlices(vector<int>& A) 
{
	int size = A.size();

	if (size < 3)
	{
		return 0;
	}

	vector<int> dp(size, 0);
	int result = 0;

	for (int i = 2; i < size; i++)
	{
		if ((A[i] - A[i-1]) == (A[i-1] - A[i-2]))
		{
			dp[i] = dp[i-1] + 1;
		}

		result = result + dp[i];
	}

	return result;
}