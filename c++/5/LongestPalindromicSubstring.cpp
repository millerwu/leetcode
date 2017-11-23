//source: https://leetcode.com/problems/longest-palindromic-substring/

/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.
Example:

Input: "cbbd"

Output: "bb"
*/

/*
 *  use DP to resolve This problem.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

string longestPalindrome(string s)
{
  vector<vector<bool>> dp(s.size(), vector<bool>(s.size()));
  for (int i = 0; i < s.size(); ++i) {
    for (int j = 0; j < s.size(); ++j) {
      if (i == j) {
        dp[i][j] = true;
        continue;
      }
      dp[i][j] = false;
    }
  }

  int first = 0, second = 0;
  int res_length = 0;

  for (int i = 1; i < dp.size(); i++) {
    for (int j = 0; j < i; j++) {
      if ((dp[i-1][j+1] || i-1 < j+1) && s[i] == s[j]) {
        dp[i][j] = true;
        if (i-j > res_length) {
          res_length = i - j;
          first = i;
          second = j;
        }
      }
    }
  }
  return s.substr(second, first-second+1);
}

int main()
{
  string s = "babad";
  string res = longestPalindrome(s);
  cout << "res = " << res << endl;
  return 0;
}
