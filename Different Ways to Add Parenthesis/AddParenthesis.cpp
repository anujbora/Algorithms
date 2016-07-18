#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, vector<int>> cache;

int evaluateExpression(char c, int a, int b)
{
    int result = 0;

    switch (c)
    {
        case '+' :
            result = a + b;
            break;
        case '-' :
            result = a - b;
            break;
        case '*' :
            result = a * b;
            break;
        default :
            break;
    }

    return result;
}

vector<int> AddParenthesis(string s)
{
    if(cache.find(s) != cache.end())
    {
        return cache[s];
    }

    vector<int> result;
    
    if (s.empty())
    {
        return result;
    }

    if(s.size() == 1)
    {
        result.push_back(stoi(s));
        cache[s] = result;
        return result;
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '+' || s[i] == '*' || s[i] == '-')
        {
            vector<int> list1 = AddParenthesis(s.substr(0, i));
            vector<int> list2 = AddParenthesis(s.substr(i+1));

            for (int j = 0; j < list1.size(); j++)
            {
                for (int k = 0; k < list2.size(); k++)
                {
                    result.push_back(evaluateExpression(s[i], list1[j], list2[k]));
                }
            }
        }
        else
        {
            continue;
        }
    }

    cache[s] = result;

    return result;
}