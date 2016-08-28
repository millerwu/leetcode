//source: https://leetcode.com/problems/combinations/

/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  static void getCombine(int n, int k, vector<int>& s, vector<vector<int> >& r)
  {
      if (k == 0)
      {
        vector<int> t = s;
        sort(t.begin(), t.end());
        r.push_back(t);
        return;
      }
      for (int i = n; i >= k ; i--)
      {
        s.push_back(i);
        getCombine(i-1, k-1, s, r);
        s.pop_back();
      }
    
  }
	static vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > result;
        vector<int> solution;
        getCombine(n, k, solution, result);
        return result;
        
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

int main (int argc, char** argv)
{
    int m = 4;
    int n = 2;
  if (argc == 3)
  {
    m = atoi(argv[1]);
    n = atoi(argv[2]);
  }
  vector<vector<int> > test = Solution::combine(m, n);
  printVector(test);
	return 0;
}
