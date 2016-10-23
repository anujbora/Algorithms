#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/**
 *	Running Time : O(n^2); where n is the number of people in the queue
 */

bool sortByHeight(pair<int, int>& a, pair<int, int>& b)
{
	return (a.first > b.first || (a.first == b.first && a.second < b.second));
}

vector<pair<int, int>> QueueReconstruction(vector<pair<int, int>>& people) 
{
	vector<pair<int, int>> result;

	sort(people.begin(), people.end(), sortByHeight);

	for (auto p : people)
	{
		result.insert(result.begin() + p.second, p);
	}

	return result;
}	