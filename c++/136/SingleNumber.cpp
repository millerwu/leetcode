//source: https://leetcode.com/problems/single-number/

/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
	int result = nums[0];
	for (int i = 1; i < nums.size(); ++i) {
		result = result ^ nums[i];
	}
	return result;
}
    
int main ()
{
	vector<int> nums = {1, 1, 2, 2, 3, 3, 5};
	int res = singleNumber(nums);
	cout << "res: " << res << endl;
	return 0;
}
