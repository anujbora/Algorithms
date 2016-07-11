#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <climits>
using namespace std;

int LongestSubstring(string& s) 
{
    unordered_map<char, int> hash;
    int len = 0;
    int start = -1;
    for(int i=0; i<s.size(); i++)
    {
        if(hash.count(s[i]) != 0)
        {
            start = max(start, hash[s[i]]);
        }
        len = max(len, i - start);
        hash[s[i]] = i;
    }
    return len;
}