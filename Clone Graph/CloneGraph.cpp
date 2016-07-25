#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

// Definition for the undirected graph
struct UndirectedGraphNode 
{
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash;

UndirectedGraphNode* cloneGraph(UndirectedGraphNode *node) 
{
    if (node == NULL)
    {
        return node;
    }
       
    if(hash.find(node) == hash.end()) 
    {
        hash[node] = new UndirectedGraphNode(node->label);
        for (auto x : node->neighbors) 
        {
            (hash[node]->neighbors).push_back( cloneGraph(x) );
        }
    }

    return hash[node];
}