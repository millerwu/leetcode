//source: https://leetcode.com/problems/trapping-rain-water/

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

*/

#include <iostream>
#include <vector>

class Solution {
public:
    static int trap(vector<int>& height) {
    	int left = 0;
    	int right = height.size()-1;
    	int secHeight = 0;
    	int res = 0;

    	while (left < right) {
    		if (height[left] < height[right])
    		{
    			if (height[left] > secHeight)
    			{
    				secHeight = height[left];
    			} else {
    				res += secHeight - height[left];
    				cout << " left = " << left << " res = " << res << endl;
    			}
    			left++;
    		} else{
    			if (height[right] > secHeight)
    			{
    				secHeight  = height[right];
    			} else {
    				res += secHeight - height[right];
    				cout << " right = " << right << " res = " << res << endl;
    			}
    			right--;
    		}
    	}
    	return res;
        
    }
};

int main ()
{
	std::vector<int> v;
	v.push_back(5);
	v.push_back(4);
	v.push_back(1);
	v.push_back(2);
	
	int res = Solution::trap(v);
	cout << " res = "  << res << endl;
	return 0;
}
