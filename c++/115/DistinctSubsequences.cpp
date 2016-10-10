//source: https://leetcode.com/problems/distinct-subsequences/

/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int numDistinct(string s, string t) {
    int s_length = s.size();
    int t_length = t.size();
    vector<vector<int> > dp(t_length+1, vector<int>(s_length+1, 0));
    for (int i = 0; i < s_length; ++i)
    {
    	dp[0][i] = 1;
    }
    for (int i = 1; i <= t_length ; ++i)
    {
    	for (int j = i; j <= s_length; ++j)
    	{
    		if (t[i-1] == s[j-1])
    		{
    			cout << "dp1 = " << dp[i][j-1] << " dp2 = " <<  dp[i-1][j-1] << endl;
    			dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
    			cout << "dp["<<i<<"]["<< j << "]=" << dp[i][j] << endl;
    		} else {
    			dp[i][j] = dp[i][j-1];
    		}
    	}
    }
    return dp[t_length][s_length];
}

int main ()
{
	string s1 = "rabbbit";
	string t1 = "rabbit";
	string s2 = "ccc";
	string t2 = "c";
	int res = numDistinct(s1, t1);
	cout << "res = " << res << endl;
	return 0;
}
