#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/**
 *  Time Complexity = O(2^n)
 */

void helper(vector<string>& result, string s, int n, int open, int close)
{
    if (open == n && close == n)
    {
        result.push_back(s);
        return;
    }
    if (open < n)
    {
        helper(result, s + "(", n, open + 1, close);
    }
    if (close < open)
    {
        helper(result, s + ")", n, open, close + 1);
    }
}

vector<string> generateParenthesis(int n) 
{
    vector<string> result;
    helper(result, "", n, 0, 0);
    return result;
}