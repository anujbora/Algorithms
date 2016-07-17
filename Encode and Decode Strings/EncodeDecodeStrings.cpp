#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string encode(vector<string> words) 
{
    string result = "";
    
    if(words.empty())
    {
        return result;
    }

    for(string s : words)
    {
        result = result + to_string(s.size()) + "@" + s;
    }

    return result;
}

vector<string> decode(string encoded_string)
{
    vector<string> result;
    
    if(encoded_string.empty())
    {
        return result;
    }

    int head = 0;

    while (head < encoded_string.size())
    {
        int at_location = encoded_string.find_first_of('@', head);
        int size = stoi(encoded_string.substr(head, at_location - head));
        result.push_back(encoded_string.substr(at_location + 1, size));
        head = head + size + 1;
    }

    return result;
}