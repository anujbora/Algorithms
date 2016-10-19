#include <iostream>
#include <algorithm>
using namespace std;

string PriceString(string s)
{
    int size = s.size();
    
    if (size == 0)
    {
        return s;
    }

    int curr_size = size;
    string result = "";

    while (curr_size > 3)
    {
        string curr_string = s.substr(curr_size - 3);
        result = "," + curr_string + result;
        s = s.substr(0, curr_size - 3);
        curr_size = curr_size - 3;
    }

    result = s + result;

    return result;
}