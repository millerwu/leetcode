//source: https://leetcode.com/problems/interleaving-string/

/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.


*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;
//use 3d dp
//dp[len1][len2][len3]
// 

bool isInterleave(string s1, string s2, string s3) {
	int len1 = s1.size();
	int len2 = s2.size();
	int len3 = s3.size();
	if (len3 != len1 + len2)
	{
		return false;
	}
	vector<vector<vector<bool> > > dp(len1+1, vector<vector<bool> >(len2+1, vector<bool>(len3+1, false)));
	dp[0][0][0] = true;

	for (int i = 0; i <= len1; ++i)
	{
		for (int j = 0; j <= len2; ++j)
		{
			for (int k = 1; k <= len3; ++k)
			{
				if (i + j != k)
				{
					continue;
				}
				// cout << " i = " << i << " j = " << j << " k = " << k << endl;
				// cout << "s1[i] = " << s1[i] << "s2[j] =" << s2[j-1] << "s3[k] = " << s3[k-1] << endl;
				if (i == 0)
				{
					dp[i][j][k] = dp[i][j-1][k-1] && s2[j-1]==s3[k-1];
				} else if (j == 0)
				{
					dp[i][j][k] = (dp[i-1][j][k-1] && s1[i-1]==s3[k-1]);
				}
				else {
					dp[i][j][k] = (dp[i-1][j][k-1] && s1[i-1]==s3[k-1]) ||
											(dp[i][j-1][k-1] && s2[j-1]==s3[k-1]);
				}
			}
		}
	}
  return dp[len1][len2][len3];
}

int main ()
{
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3_1 = "aadbbcbcac";
	string s3_2 = "aadbbbaccc";
	cout << "test1 res = " << isInterleave(s1, s2, s3_1) << endl;
	cout << "test2 res = " << isInterleave(s1, s2, s3_2) << endl;
	return 0;
}
