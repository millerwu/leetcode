//source: https://leetcode.com/problems/single-number-ii/

/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include <iostream>
#include <vector>

using namespace std;

int singleNumber(vector<int>& nums) {
  int count[32] = {0};
  int result = 0;
  for (int i = 0; i < 32; ++i) {
    for (int j = 0; j < nums.size(); ++j) {
      if (nums[j] >> i & 1) {
        count[i]++;
      }
    }
    result |= ((count[i]%3) << i);
  }
  return result;
}

int main ()
{
  vector<int> nums = {1, 3, 3, 3};
  int res = singleNumber(nums);
  cout << "res = " << res << endl;
	return 0;
}
