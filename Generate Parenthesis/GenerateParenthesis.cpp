#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/**
 *  Time Complexity = O(2^n)
 */

void helper(vector<string>& result, string s, int left, int right)
{
    if (left == 0 && right == 0)
    {
        result.push_back(s);
        return;
    }
    if (left > 0)
    {
        helper(result, s + "(", left - 1, right + 1);
    }
    if (right > 0)
    {
        helper(result, s + ")", left, right - 1);
    }
}

vector<string> generateParenthesis(int n) 
{
    vector<string> result;
    helper(result, "", n, 0);
    return result;
}