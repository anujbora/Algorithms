#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/**
 *  Time Complexity : O(n); where n is the number of elements in the array
 *  Space Complexity : O(n)
 */

vector<int> twoSum(vector<int>& numbers, int target) 
{
    //Key is the number and value is its index in the vector.
    unordered_map<int, int> cache;
    vector<int> result;

    for (int i = 0; i < numbers.size(); i++) 
    {
        int numberToFind = target - numbers[i];

        //if numberToFind is found in map, return them
        if (cache.find(numberToFind) != cache.end()) 
        {
            result.push_back(cache[numberToFind]);
            result.push_back(i);            
            return result;
        }

        //number was not found. Put it in the map.
        cache[numbers[i]] = i;
    }

    return result;
}