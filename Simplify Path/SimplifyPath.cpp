#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

string SimplifyPath(string& s) 
{
    stringstream ss(s);
    string temp = "";
    vector<string> vec;
    while(getline(ss, temp, '/'))
    {
        if(temp == "." || temp == "")
        {
            continue;
        }
        else if(temp == "..")
        {
            if(!vec.empty())
            {
                vec.pop_back();
            }
        }
        else
        {
            vec.push_back(temp);
        }
    }
    if(s.empty())
    {
        return "/";
    }
    string result = "";
    for(int i=0; i<vec.size(); i++)
    {
        result = result + "/" + vec[i];
    }
    return result;
}