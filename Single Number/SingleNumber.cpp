#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 *	Running Time : O(n); where n is the number of elements in the input
 *	Space Complexity : O(1)
 */

 /**
  *	The idea is :
	*	num ^ num = 0;	// XOR of a number with itself is 0
	*	num ^ 0 = num;	// XOR of a number with 0 is the number itself
	* Thus, (num1 ^ num1) ^ (num2 ^ num2) ^ num3 = num3
	*/

int SingleNumber(vector<int>& nums)
{
	int result = 0;

	for (int n : nums)
	{
		result = result ^ n;
	}

	return result;
}
