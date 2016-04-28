//source: https://leetcode.com/problems/combination-sum/

/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	static void combinationSumHelper(vector<int>& candidates, int start, int target, vector<int>& condition, vector<vector<int> >& result) {
		if (target < 0)
		{
			return;
		}
		if (target == 0)
		{
			result.push_back(condition);
			return;
		}
		for (int i = start; i < candidates.size(); ++i)
		{
			if (i > start && (candidates[i] == candidates[i-1]))
			{
				continue;
			}
			condition.push_back(candidates[i]);
			combinationSumHelper(candidates, i, target-candidates[i], condition, result);
			condition.pop_back();
		}

	}
	static vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
		vector<vector<int> > res;
		std::vector<int> tmp;
		sort(candidates.begin(), candidates.end());
		combinationSumHelper(candidates, 0, target, tmp, res);
			
		return res;
    }
    
};

int main ()
{
	std::vector<int> test;
	test.push_back(2);
	test.push_back(3);
	test.push_back(7);

	std::vector<vector<int> > res = Solution::combinationSum(test, 18);
	cout << res.size() << endl;

	for (int i = 0; i < res.size(); ++i)
	{
		for (int j = 0; j < res[i].size(); ++j)
		{
			cout <<res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
