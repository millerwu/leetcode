//source: https://leetcode.com/problems/two-sum/

/*
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution.

Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  unordered_map<int, int> map;
  for (int i = 0; i < nums.size() ; ++i) {
    map[nums[i]] = i;
  }
  vector<int> res;
  for (int i = 0; i < nums.size(); ++i) {
    if (map.find(target - nums[i]) != map.end()) {
      res.push_back(i);
      res.push_back(map[target - nums[i]]);
      break;
    }
  }
  return res;
}

void print(vector<int> a)
{
  for (int i = 0; i < a.size(); ++i) {
    cout << a[i] << endl;
  }
}


int main ()
{
  vector<int> nums = {2, 7, 11, 15};
  vector<int> res = twoSum(nums, 9);
  print(res);
	return 0;
}
