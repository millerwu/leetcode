//source: https://leetcode.com/problems/jump-game/

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

#include <iostream>
#include <vector>

class Solution {
public:
    static bool canJump(vector<int>& nums) {
		if (nums.size() <= 1)
		{
			return true;
		}
		if (nums[0] == 0)
		{
		    return false;
		}
		bool flag = false;
		for (int i = 1; i < nums.size()-1; i++)
		{
		    flag = false;
			if (nums[i] == 0)
			{
				for (int j = i-1; j >= 0; j--)
				{
					if ((i - j) < (nums[j] - nums[i]))
					{
						flag = true;
						break;
					}
				}
				if (!flag)
				{
					return false;
				}
			}
		}
		return true;
    }
};

int main ()
{
	vector<int> nums;
	nums.push_back(0);
	// nums.push_back(0);
	// nums.push_back(0);
	// nums.push_back(1);
	// nums.push_back(4);
	bool res = Solution::canJump(nums);
	cout<< res << endl;
	return 0;
}
