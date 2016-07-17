#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string addRange(vector<string>& result, int n1, int n2)
{
    if(n1 == n2)
    {
        return to_string(n1);
    }
    else
    {
        return to_string(n1) + "->" + to_string(n2);
    }
}

vector<string> MissingRanges(vector<int>& nums, int start, int end) 
{
    int next = start;
    vector<string> result;
    for(int i = 0; i < nums.size(); i++)
    {
        if(nums[i] < start)
        {
            continue;
        }
        else if(nums[i] == next)
        {
            next++;
            continue;
        }
        else if(nums[i] < end)
        {
            result.push_back(addRange(result, next, nums[i] - 1));
        }
    }

    if(next <= end)
    {
        result.push_back(addRange(result, next, end));
    }

    return result;
}