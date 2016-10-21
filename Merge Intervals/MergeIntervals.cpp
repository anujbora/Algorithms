#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 *	Running Time : O(n logn); where n is the number of intervals in the input
 */

/**
 *	Definition for an interval
 */
struct Interval 
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool comparator(Interval& a, Interval& b)
{
	return a.start < b.start;
}

vector<Interval> merge(vector<Interval>& intervals) 
{
	vector<Interval> results;

	if (intervals.empty())
	{
		return results;
	}

	sort(intervals.begin(), intervals.end(), comparator);

	results.push_back(intervals[0]);

	for (int i = 1; i < intervals.size(); i++)
	{
		if (results.back().end <= intervals[i].start)
		{
			results.back().end = intervals[i].end;
		}
		else
		{
			results.push_back(intervals[i]);
		}
	}

	return results;
}