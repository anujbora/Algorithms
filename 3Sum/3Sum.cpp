#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int> > threeSum(vector<int>& nums) 
{
    vector<vector<int> > result;
    
    sort(nums.begin(), nums.end());
    
    for(int i=0; i<nums.size(); i++)
    {
        int target = -nums[i];
        // Target has to be negative. If target is positive, 
        // impossible for sum to be 0 as array is sorted
        if(target < 0)
        {
            break;
        }

        int front = i+1;
        int back = nums.size()-1;
        
        while (front < back)
        {
            int sum = nums[front] + nums[back];
            if (sum < target)
            {
                front++;
            }
            else if (sum > target)
            {
                back--;
            }
            // Triplet Found
            else
            {
                vector<int> triplet (3,0);
                triplet[0] = -target;
                triplet[1] = nums[front];
                triplet[2] = nums[back];
                result.push_back(triplet);
            }
        }
    }
    return result;
}