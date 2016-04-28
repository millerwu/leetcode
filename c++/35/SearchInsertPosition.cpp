//source: https://leetcode.com/problems/search-insert-position/

/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

#include <iostream>
#include <vector>

class Solution {
public:
    static int searchInsert(vector<int>& nums, int target) {
        int res = 0;
        if (nums.size() == 0)
        {
        	return res;
        }
        int start = 0;
        int end = nums.size() - 1;
        int mid;
        while (start < end -1) {
        	mid = (start+end)/2;
        	if (target <= nums[mid])
        	{
        		end = mid;
        	} else {
        		start = mid;
        	}
        }
        if (target <= nums[start])
        {
        	return start;
        } else if (target > nums[end]){
        	return end+1;
        } else {
        	return end;
        }
    }
};

int main ()
{
	std::vector<int> test;
	test.push_back(1);
	test.push_back(3);
	test.push_back(5);
	test.push_back(5);
	test.push_back(7);

	int res = Solution::searchInsert(test, 5);
	cout << "res = " << res;
	return 0;
}
