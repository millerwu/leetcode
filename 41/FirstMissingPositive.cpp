//source: https://leetcode.com/problems/first-missing-positive/
//data: 2016/03/09
//author: WuMiaoLiang

/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    static int firstMissingPositive(vector<int>& nums) {
        
        int res = 1;
        if (nums.size() == 0)
        {
        	return res;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
        	while (nums[i] > 0 && nums[i] != i+1 && nums[i] != nums[nums[i]-1] && nums.size() > nums[i]-1)
        	{
        		swap(nums[i], nums[nums[i]-1]);
        	}
        }
        for (int i = 0; i < nums.size(); ++i)
        {
        	if (nums[i] != i+1)
        	{
        		return i+1;
        	}
        }
        return nums.size()+1;
    }
};

int main ()
{
	std::vector<int> v;
	v.push_back(3);
	v.push_back(4);
    v.push_back(-1);
    v.push_back(1);
	int res = Solution::firstMissingPositive(v);
	cout << "res = " << res << endl;
	return 0;
}
