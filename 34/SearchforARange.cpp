//source: https://leetcode.com/problems/search-for-a-range/

/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

#include <iostream>
#include <vector>

class Solution {
public:
    static vector<int> searchRange(vector<int>& nums, int target) {
 		std::vector<int> res;
 		if (nums.size() == 0 || target < nums[0] || target > nums[nums.size()-1])
		{
			res.push_back(-1);
			res.push_back(-1);
			return res;
		}
		int start = 0;
		int end = nums.size()-1;
		
		while (start < end-1) {
			int mid = (start+end)/2;
			if (target <= nums[mid])
			{
				end = mid;
			} else {
				start = mid;
			}
		}
		if (target == nums[start])
			res.push_back(start);
		else if (target == nums[end])
			res.push_back(end);
		else{
			res.push_back(-1);
			res.push_back(-1);
			return res;
		}
		start = 0;
		end = nums.size()-1;
		while (start < end-1) {
			int mid = (start+end)/2;
			if (target >= nums[mid])
			{
				start = mid;
			} else {
				end = mid;
			}
		}
		if (target == nums[end])
			res.push_back(end);
		else if (target == nums[start])
			res.push_back(start);
		else{
			res.push_back(-1);
			res.push_back(-1);
			return res;
		}
		return res;
    }
};

int main ()
{
	std::vector<int> test;
	test.push_back(2);
	test.push_back(2);
	
	std::vector<int> res;
	res = Solution::searchRange(test, 2);
	for (int i = 0; i < res.size(); ++i)
	{
		cout << res[i] << "\n";
	}
	return 0;
}
