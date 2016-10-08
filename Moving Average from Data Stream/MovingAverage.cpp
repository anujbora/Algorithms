#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class MovingAverage 
{
private:
    queue<int> q;
    int size;
    double sum;

public:
    MovingAverage(int s)
    {
        size = s;
        sum = 0; 
    }
    
    double next(int val) 
    {
        sum = sum + val;
        q.push(val);
        
        if (q.size() <= size)
        {
            return sum / q.size();
        }
        else
        {
            sum = sum - q.front();
            q.pop();
            return sum / size;
        }
    }
};