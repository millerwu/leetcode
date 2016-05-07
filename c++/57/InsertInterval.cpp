//source: https://leetcode.com/problems/insert-interval/

/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

*/

#include <iostream>
#include <vector>
#include <algorithm>

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
	static bool compare(Interval l, Interval r)
	{
		return (l.start == r.start) ? (l.end < r.end) : l.start < r.start;
	}
	static bool overlap(Interval l, Interval r)
	{
		if (l.start <= r.start && l.end >= r.start)
		{
			return true;
		} else if (l.start >= r.start && r.end >= l.start)
		{
			return true;
		} else {
			return false;
		}
	}

	static vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
		if (intervals.size() == 0)
		{
			res.push_back(newInterval);
			return res;
		}
		sort(intervals.begin(), intervals.end(), compare);
		bool added = false;
		for (int i = 0; i < intervals.size(); i++)
		{
			if (!added && overlap(intervals[i], newInterval))
			{
				cout <<"case 1"<< endl;
				newInterval.start = min(newInterval.start, intervals[i].start);
				newInterval.end = max(newInterval.end, intervals[i].end);
			} else if (!added && intervals[i].start > newInterval.end)
			{
				cout <<"case 2"<< endl;
				res.push_back(newInterval);
				res.push_back(intervals[i]);
				added  =true;
			} else if (!added && intervals[i].end < newInterval.start)
			{
				cout <<"case 3"<< endl;
				res.push_back(intervals[i]);
			}else if (added)
			{
				cout <<"case 4"<< endl;
				res.push_back(intervals[i]);
			}
		}
		if (!added)
		{
			res.push_back(newInterval);
		}
		return res;
    }
    
};

int main ()
{
	Interval i1(1,5);
	// Interval i2(1,5);
    // Interval i3(6,7);
    // Interval i4(8,10);
	// Interval i5(12,16);
    vector<Interval> intervals;
    intervals.push_back(i1);
    // intervals.push_back(i2);
    // intervals.push_back(i3);
    // intervals.push_back(i4);
	// intervals.push_back(i5);
	Interval new_i(5,7);
	
	vector<Interval> r = Solution::insert(intervals, new_i);
    
    for(int i=0; i<r.size(); i++){
        cout << "[ " << r[i].start << ", " << r[i].end << " ] ";
    }
    cout <<endl;

	return 0;
}
