#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 *  Time Complexity : O(nlogn) where n is the number of intervals
 *  Space Complexity : O(n)
 */

struct Interval
{
    int start;
    int end;
};

int MeetingRooms(vector<Interval>& intervals) 
{
    int size = intervals.size();

    if (size <= 1)
    {
        return size;
    }

    vector<int> starts(size);
    vector<int> ends(size);

    for (int i = 0; i < size; i++)
    {
        starts[i] = intervals[i].start;
        ends[i] = intervals[i].end;
    }

    int numRooms = 0;
    int currRooms = 0;
    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    int i = 0;
    int j = 0;

    while (i < size && j < size)
    {
        if (starts[i] < ends[j])
        {
            currRooms++;
            numRooms = max(numRooms, currRooms);
            i++;
        }
        else
        {
            numRooms--;
            j++;
        }
    }

    return numRooms;
}