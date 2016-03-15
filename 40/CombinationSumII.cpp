//source: https://leetcode.com/problems/combination-sum-ii/

/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

	static void combinationSum2Helper(vector<int>& candidates, int start, int target, vector<int>& condition, vector< vector<int> >& res) {
		if (target == 0)
		{
			res.push_back(condition);
			return;
		}

		for (int i = start; i <candidates.size() ; ++i)
		{
			if (target - candidates[i] < 0)
			{
				return;
			}
			if (i > start && candidates[i] == candidates[i-1])
			{
				continue;
			}
			condition.push_back(candidates[i]);
			combinationSum2Helper(candidates, i+1, target - candidates[i], condition, res);
			condition.pop_back();
		}
		return;
	}



	static vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());

		vector< vector<int> > res;
		vector<int> tmp;

		combinationSum2Helper(candidates, 0, target, tmp, res);
		return res;
    }
    
};

static inline printVector(vector<vector<int> > input) {
	for (int i = 0; i < input.size(); ++i)
	{
		for (int j = 0; j <input[i].size() ; ++j)
		{
			cout << " " << input[i][j];
		}
		cout<<endl;
	}
}
int main ()
{
	std::vector<int> test;
	test.push_back(10);
	test.push_back(2);
	test.push_back(2); 
	test.push_back(7);
	test.push_back(6);
	test.push_back(1);
	test.push_back(5);
	vector<vector<int> > res = Solution::combinationSum2(test, 10);
	cout << " res =  " << res.size() << endl;

	printVector(res);

	return 0;
}
