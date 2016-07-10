#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iterator>
using namespace std;

void bfs(vector<string>& dictionary, string current_word, queue<string> &q)
{
    for(int i=0; i<current_word.size(); i++)
    {
        char current_character = current_word[i];
        for(int j=0; j<26; j++)
        {
            vector<string>::iterator it = find(dictionary.begin(), dictionary.end(), current_word);
            current_word[i] = j + 'a';
            if(it != dictionary.end())
            {
                q.push(current_word);
                dictionary.erase(it);
            }
        }
        current_word[i] = current_character;
    }
}

int WordLadder(vector<string>& dictionary, string source, string target) 
{
    if(source == target)
    {
        return 0;
    }
    queue<string> q;
    q.push(source);
    dictionary.push_back(source);
    int distance = 1;
    while(!q.empty())
    {
        int size = q.size();
        while(size)
        {
            string current_word = q.front();
            q.pop();
            if(current_word == target)
            {
                return distance;
            }
            bfs(dictionary, current_word, q);
            distance++;
            size--;
        }
    }
    return 0;
}