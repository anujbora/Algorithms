#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string largestNumber(vector<int>& nums) 
{
    vector<string> arr;

    for (int n : nums)
    {
        arr.push_back(to_string(n));
    }

    sort(begin(arr), end(arr), [](string &s1, string &s2){ return s1+s2 > s2+s1; });
    
    string res;

    for(string s : arr)
    {
        res = res + s;
    }    

    return  res;   
}