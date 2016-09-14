#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

bool StrobogrammaticNumber(string& num)
{
    unordered_map<char, char> dict;
    
    dict['0'] = '0';
    dict['1'] = '1';
    dict['6'] = '9';
    dict['8'] = '8';
    dict['9'] = '6';

    int left = 0;
    int right = num.size() - 1;

    while (left <= right)
    {
        if (dict.find(num[left]) == dict.end())
        {
            return false;
        }

        if (dict[num[left]] != num[right])
        {
            return false;
        }
    }

    return true;
}  