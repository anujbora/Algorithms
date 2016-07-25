#include <iostream>
#include <algorithm>
using namespace std;

/**
 *  Time Complexity : O(nm); where n is the size of first string and m is the
                            size of second string
 *  Space Complexity : O(1)
 */

string MultiplyStrings(string& s1, string &s2) 
{
    if (s1.size() == 0 || s2.size() == 0)
    {
        return "0";
    }
    
    string result(s1.size() + s2.size(), '0');

    for (int i = s1.size() - 1; i >= 0; i--)
    {
        int carry = 0;
        for (int j = s2.size() - 1; j >= 0; j--)
        {
            int temp = (result[i+j+1] - '0') + ((s1[i] - '0') * (s2[j] - '0')) + carry;
            result[i+j+1] = temp % 10 + '0';
            carry = temp / 10;
        }
        result[i] = carry + '0';
    }

    // Skip leading zeros (if any)
    size_t startpos = result.find_first_not_of('0');
    if (string::npos != startpos) 
    {
        return result.substr(startpos);
    }
        
    return "0";
}