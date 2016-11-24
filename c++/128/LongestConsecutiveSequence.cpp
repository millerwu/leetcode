//source: https://leetcode.com/problems/longest-consecutive-sequence/

/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int longestConsecutive(vector<int>& nums) {
	unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); ++i) {
		map[nums[i]] = i;
	}

	int res = 0;

	for (int j = 0; j < nums.size(); ++j) {
		int count = 0;
		int temp = nums[j];
		while (map.find(temp) != map.end()) {
			map.erase(map.find(temp));
			temp++;
			count++;
		}
		temp = nums[j]-1;
		while (map.find(temp) != map.end()) {
			map.erase(map.find(temp));
			count++;
			temp--;
		}
		res = res > count ? res : count;
	}
	return res;
}

int main ()
{
	vector<int> nums = {100, 4, 200, 1, 3, 2};
	int res = longestConsecutive(nums);
	cout << " res = " << res << endl;
	return 0;
}
