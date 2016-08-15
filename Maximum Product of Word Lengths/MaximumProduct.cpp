#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/**
 *  Time Complexity = O(n^2) where n is the number of words in array
 *  Space Complexity = O(n)
 */

int generateMask(string &s)
{
    int mask = 0;
    for (char c : s)
    {
        mask = mask | (1 << (c - 'a'));
    }
    return mask;
}

int MaximumProduct(vector<string>& words) 
{
    vector<pair<int, int>> hash;
    
    for (string s : words)
    {
        hash.push_back(make_pair(s.size(), generateMask(s)));  
    }
    
    int result = 0;
    for (int i = 0; i < words.size(); i++)
    {
        for (int j = i + 1; j < words.size(); j++)
        {
            if((hash[i].second & hash[j].second) == 0)
            {
                int curr_size = hash[i].first * hash[j].first;
                result = max(result, curr_size);
            }
        }
    }
    
    return result;
}