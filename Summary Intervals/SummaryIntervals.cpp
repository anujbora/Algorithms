#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 *	Running Time : O(n); where n is the number of elements in the input
 */

string make_range(int a, int b)
{
    if (a == b)
    {
        return to_string(a);
    }
    else
    {
        return to_string(a) + "->" + to_string(b);
    }
}

vector<string> summaryRanges(vector<int>& nums) 
{
	vector<string> result;
 
 	if (nums.empty())
 	{
    	return result;
 	}
 
 	if (nums.size() == 1)
 	{
    	result.push_back(to_string(nums[0]));
    	return result;
 	}

 	int size = nums.size() - 1;
 	int start = 0;
 
 	for (int i = 1; i <= size; i++)
 	{
    	if (nums[i] == (nums[i-1] + 1))
    	{
       		if(i == size)
        	{
            	result.push_back(make_range(nums[start], nums[i]));
            	break;
        	}
        	continue;
     	}
     	else
     	{
        	result.push_back(make_range(nums[start], nums[i - 1]));
        	start = i;
        
        	if (i == size)
        	{
            	result.push_back(make_range(nums[start], nums[i]));
            	break;
         	}
     	}
 	}
 
	return result;
}