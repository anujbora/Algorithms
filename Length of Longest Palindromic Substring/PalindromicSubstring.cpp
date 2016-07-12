#include <iostream>
#include <algorithm>
using namespace std;

/**
 *  Time Complexity = O(n^2); n is the length of input string
 *  Space Complexity = O(1);
 */

int palindromeChecker(string &s, int start, int end)
{
    while(start>=0 && end<s.size() && s[start] == s[end])
    {
        start--;
        end++;
    }
    return end-start-1;
}

int PalindromicSubstring(string& s) 
{
    if(s.empty())
    {
        return 0;
    }
    int maxLen = 0;

    for(int i=0; i<s.size()-1; i++)
    {
        int a = palindromeChecker(s, i, i+1);
        int b = palindromeChecker(s, i, i);
        maxLen = max(maxLen, max(a, b));
    }

    return maxLen;
}