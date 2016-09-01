//source: https://leetcode.com/problems/subsets/

/*
Given a set of distinct integers, nums, return all possible subsets.

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
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
    static void getCombine(vector<int>& nums, int s, int k, vector<int>& output, vector<vector<int> >& res)
    {
      if (k==0)
      {
        vector<int> r = output;
        sort(r.begin(), r.end());
        res.push_back(r);
        return;
      }
      for (int i=s; i>=0; --i)
      {
        output.push_back(nums[i]);
        getCombine(nums, i-1, k-1, output, res);
        output.pop_back();
      }
    }

    static vector<vector<int> > combine(vector<int>& nums, int k)
    {
        vector<vector<int> > res;
        vector<int> output;
        getCombine(nums, nums.size()-1, k, output, res);
        return res;
    }

    static vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > res;
        vector<vector<int> > tmp;
        for (int i = 0; i <= nums.size(); ++i)
        {
          tmp = combine(nums, i);
          res.insert(res.end(), tmp.begin(), tmp.end());
        }
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
  for (int i = 1; i < 4; ++i)
  {
    test.push_back(i);
  }
  vector<vector<int> > res = Solution::subsets(test);
  printVector(res);
	return 0;
}
