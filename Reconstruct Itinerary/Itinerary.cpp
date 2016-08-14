#include <algorithm>
#include <vector>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

/**
 *  Time Complexity = O(n) where n is the number of tickets
 */

unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;

void dfs(string airport, vector<string>& itinerary)
{
    auto& destinations = graph[airport];
    while (!destinations.empty())
    {
        string curr = destinations.top();
        destinations.pop();
        dfs(curr, itinerary);
    }
    itinerary.push_back(airport);
    return;
}

vector<string> findItinerary(vector<pair<string, string>> tickets) 
{
    // make graph
    for (pair<string, string> p : tickets)
    {
        graph[p.first].push(p.second);
    }

    vector<string> itinerary;
    dfs("JFK", itinerary);
    reverse(itinerary.begin(), itinerary.end());
    return itinerary;
}