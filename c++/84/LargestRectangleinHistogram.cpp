//source: https://leetcode.com/problems/largest-rectangle-in-histogram/

/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given heights = [2,1,5,6,2,3],
return 10.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    static int largestRectangleArea(vector<int>& heights) {

    }

    // This solution will be time limit exceeded
    static int largestRectangleArea1(vector<int>& heights) {
        if (heights.size() <= 0)
        {
        	return 0;
        }
        int maxArea = 0;
        for (int i = 0; i < heights.size(); ++i)
        {
        	int lowest = heights[i];
        	for (int j = i; j >=0 ; --j)
        	{
        		lowest = heights[j] > lowest ? lowest : heights[j];
        		int area = lowest * (i-j+1);
        		maxArea = maxArea > area ? maxArea : area;
        	}
        }
        return maxArea;
    }
};

void printVector(std::vector<int> v)
{
	for (int i = 0; i < v.size(); ++i)
	{
	}
}

int main ()
{
	vector<int> test;
	test.push_back(1);
	test.push_back(1);
	test.push_back(5);
	test.push_back(6);
	test.push_back(2);
	test.push_back(3);

	int res = Solution::largestRectangleArea(test);

	cout << "res = " << res << endl;

	return 0;
}
