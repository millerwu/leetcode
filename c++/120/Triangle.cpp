//source: https://leetcode.com/problems/triangle/

/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
*/

//use dp to solve this problem

#include <iostream>
#include <vector>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
    int height = triangle.size();
    int width = triangle[height-1].size();
    vector<vector<int> > dp(height+1, vector<int>(width+1, 0));
    int res = INT_MAX;
   	for (int i = 1; i <= height; ++i)
   	{
   		for (int j = 1; j <= triangle[i-1].size(); ++j)
   		{
   			if (j == 1)
   			{
   				dp[i][j] = dp[i-1][j] + triangle[i-1][j-1];
   			} else if (j == triangle[i-1].size()){
   				dp[i][j] = dp[i-1][j-1] + triangle[i-1][j-1];
   			}else {
   				dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i-1][j-1];
   			}
   			// cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << endl;
   			if (i == height)
   			{
   				res = min(res, dp[i][j]);
   			}
   		}
   	}
   	return res;
}

void printVector(vector<vector<int> > v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size() ; ++j)
		{
			/* code */
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}
int main ()
{
	vector<vector<int> > v = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
	printVector(v);
	int sum = minimumTotal(v);
	cout << "sum = " << sum << endl;
	return 0;
}
