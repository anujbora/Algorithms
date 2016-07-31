#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;

/**
 *  NestedIterator object will be instantiated and called as such:
 *  NestedIterator i(nestedList);
 *  while (i.hasNext()) cout << i.next();
 */

/**
 *  This is the interface that allows for creating nested lists.
 */
class NestedInteger 
{
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator 
{
public:
    NestedIterator(vector<NestedInteger> &nestedList) 
    {
        for (int i = nestedList.size() - 1; i >= 0; i--)
        {
            s.push(nestedList[i]);
        }
    }

    int next() 
    {
        NestedInteger current = s.top();
        s.pop();
        return current.getInteger();
    }

    bool hasNext() 
    {
        while (!s.empty())
        {
            NestedInteger curr = s.top();
            if (curr.isInteger())
            {
                return true;
            }
            s.pop();
            for (int i = curr.getList().size() - 1; i >= 0; i--)
            {
                s.push(curr.getList()[i]);
            }
        }
        return false;
    }
    
private:
    stack<NestedInteger> s;
};