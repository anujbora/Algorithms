#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

/**
 *  Time Complexity : O(n); where n is the number of charatcers in the string
 *  Space Complexity : O(1)
 */

int LongestSubstring(string& s, int k) 
{
    unordered_map<char, int> dict;
    int start = 0;
    int count = 0;
    int len = 0;

    for (int i = 0; i < s.size(); i++)
    {
        dict[s[i]]++;

        if (dict[s[i]] == 1)
        {
            count++;

            while (count > k)
            {
                dict[s[start]]--;
                if (dict[s[start]] == 0)
                {
                    count--;
                }
                start++;
            }
        }

        len = max(len, i - start + 1);
    }

    return len;
}