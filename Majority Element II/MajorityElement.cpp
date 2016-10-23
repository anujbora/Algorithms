#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 *	Running Time : O(n); where n is the number of elements in the input
 */

vector<int> MajorityElement(vector<int>& nums) 
{
	vector<int> result;
	int candidate1 = 0;
	int candidate2 = 0;
	int count1 = 0;
	int count2 = 0;
	int n = nums.size();

	for (int i = 0; i < n; i++)
	{
		if (nums[i] == candidate1)
		{
			count1++;
		}
		else if (nums[i] == candidate2)
		{
			count2++;
		}
		else
		{
			if (count1 == 0)
			{
				candidate1 = nums[i];
			}
			else if(count2 == 0)
			{
				candidate2 = nums[i];
			}
			else
			{
				count1--;
				count2--;
			}
		}
	}

	count1 = 0;
	count2 = 0;

	for (int i = 0; i < n; i++)
	{
		if (nums[i] == candidate1)
		{
			count1++;
		}
		else if(nums[i] == candidate2)
		{
			count2++;
		}
	}

	if (count1 > (n/3))
	{
		result.push_back(candidate1);
	}

	if (count2 > (n/3))
	{
		result.push_back(candidate2);
	}

	return result;
}
	