#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

/**
 *  Time Complexity for addNUM() : O(log n)
 *  Time Complexity for findMedian() : O(1)
 *  Space Complexity : O(n)
 */

class MedianFinder 
{
public:
    // Adds a number into the data structure.
    void addNum(int num) 
    {
        if (maxPQ.empty() || num < maxPQ.top())
        {
            maxPQ.push(num);
        }
        else
        {
            minPQ.push(num);
        }

        if (maxPQ.size() > (minPQ.size() + 1))
        {
            minPQ.push(maxPQ.top());
            maxPQ.pop();
        }
        else if (minPQ.size() > (maxPQ.size() + 1))
        {
            maxPQ.push(minPQ.top());
            minPQ.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() 
    {
        if (maxPQ.size() == minPQ.size())
        {
            return ((maxPQ.top() + minPQ.top()) / 2.0);
        }

        if (maxPQ.size() > minPQ.size())
        {
            return maxPQ.top();
        }
        else
        {
            return minPQ.top();
        }
        
    }

private:
    priority_queue<int> maxPQ;
    priority_queue<int, vector<int>, greater<int>> minPQ;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();