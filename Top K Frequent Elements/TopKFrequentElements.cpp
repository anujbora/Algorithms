#include <iostream>
#include <vector>
#include <algorithm>
#include <priority_queue>
#include <unordered_map>
using namespace std;

/**
 *  Time Complexity : O(nlog(n-k)); where n is the number of elements in the array
 */

vector<int> topKFrequentElements(vector<int>& numbers, int k) 
{
    unordered_map<int, int> hm;
    vector<int> result;

    for (int i : numbers)
    {
        hm[i]++;
    }

    priority_queue<pair<int, int>> pq;

    for (pair<int, int> p : hm)
    {
        pq.push(make_pair(p.second, p.first));
    }

    if (pq.size() >= k)
    {
        while (k)
        {
            result.push_back(pq.top().second);
            pq.pop();
            k--;
        }
    }

    return result;
}