//source: https://leetcode.com/problems/subsets-ii/

/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	static void subsetsHelper(vector<int>& nums, int index, vector<int>& condition, vector<vector<int> >& res)
	{
		for (int i = index; i < nums.size(); ++i)
		{
			cout << "index = " << index << endl;
			condition.push_back(nums[i]);
			res.push_back(condition);
			subsetsHelper(nums, ++index, condition, res);
			condition.pop_back();
			while (i<nums.size()-1 && nums[i]==nums[i+1])
			{
				i++;
				index++;
			}
		}
	}
    static vector<vector<int> > subsetsWithDup(vector<int>& nums) {
    	vector<vector<int> > res;
    	std::vector<int> condition;
    	sort(nums.begin(), nums.end());
    	res.push_back(condition);
    	if (nums.size() <=0)
    	{
    		return res;
    	}
    	subsetsHelper(nums, 0, condition, res);
    	// sort(res.begin(), res.end());
    	return res;
    }
};
void printVector(vector< vector<int> > test)
{
	for (int i = 0; i < test.size(); ++i)
	{
		for (int j = 0; j < test[i].size(); ++j)
		{
			cout << " " << test[i][j];
		}
		cout << endl;
	}
}

int main ()
{
	vector<int> test;
	test.push_back(1);
	test.push_back(1);
	test.push_back(2);
	test.push_back(2);
	test.push_back(2);
	test.push_back(3);
	vector<vector<int> > res = Solution::subsetsWithDup(test);
	printVector(res);
	return 0;
}
