//source: https://leetcode.com/problems/merge-intervals/

/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
*/

#include <iostream>
#include <vector>
#include <algorithm>

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
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
		return (l.start==r.start) ? l.end<r.end : l.start<r.start; 
	}
    static vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
		if (intervals.size() == 0)
		{
			return res;
		}
		sort(intervals.begin(), intervals.end(), compare);
		for(int i=0; i<intervals.size(); i++){
        	cout << "[ " << intervals[i].start << ", " << intervals[i].end << " ] ";
		}
		cout <<endl;
		for (int i = 0; i<intervals.size(); i++)
		{
			int size = res.size();
			if (size>0 && intervals[i].start<=res[size-1].end)
			{
				res[size-1].end = max(res[size-1].end, intervals[i].end);
			} else {
				res.push_back(intervals[i]);
				cout << intervals[i].start << " "<< intervals[i].end<< endl; 
			}
		}
		return res;
    }
};

int main ()
{
	Interval i1(1,4);
    Interval i2(2,5);
    // Interval i3(3,5);
    // Interval i4(15,18);
    vector<Interval> intervals;
    intervals.push_back(i1);
    intervals.push_back(i2);
    // intervals.push_back(i3);
    // intervals.push_back(i4);
    
    vector<Interval> r = Solution::merge(intervals);
    
    for(int i=0; i<r.size(); i++){
        cout << "[ " << r[i].start << ", " << r[i].end << " ] ";
    }
    cout <<endl;

	return 0;
}
