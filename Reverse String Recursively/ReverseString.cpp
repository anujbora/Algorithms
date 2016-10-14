#include <iostream>
#include <algorithm>
using namespace std;

string ReverseString(string s) 
{
    if (s.size() <= 1)
    {
        return s;
    }

    return ReverseString(s.substr(1)) + s[0];
}