#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 *  Time Complexity : O(nlogn) where n is the number of intervals
 *  Space Complexity : O(1)
 */

struct Interval
{
    int start;
    int end;
};

bool compare(Interval& interval1, Interval& interval2)
{
    return interval1.end < interval2.end;
}

bool MeetingRooms(vector<Interval>& intervals) 
{
    sort(intervals.begin(), intervals.end(), compare);

    for (int i = 1; i < intervals.size(); i++)
    {
        if (intervals[i].start < intervals[i-1].end)
        {
            return false;
        }
    }
    return true;
}