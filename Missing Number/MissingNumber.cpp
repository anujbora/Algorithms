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
	* S0, a ^ b ^ b = a;
	* Thus, (num1 ^ (index of num1)) ^ (num2 ^ (index of num2)) ^ num3 = num3
	*/

int MissingNumber(vector<int>& nums)
{
	int result = 0;
	int i = 0;
	
	for (i = 0; i < nums.size(); i++)
	{
		result = result ^ nums[i] ^ i;
	}

	return result ^ i;
}
