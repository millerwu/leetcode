//source: https://leetcode.com/problems/scramble-string/

/*
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t
To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t
We say that "rgeat" is a scrambled string of "great".

Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a
We say that "rgtae" is a scrambled string of "great".

Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
*/

#include <iostream>
#include <string>
#include <sys/time.h>
#include <vector>

using namespace std;

class Solution {
 public:
    static bool isScramble_recursion(string s1, string s2) {
      if (s1.size()!=s2.size())
      {
        return false;
      }
      if (s1.size()==0 || s1==s2)
      {
        return true;
      }
      for (int i = 1; i < s1.size(); ++i)
      {
        if((isScramble_recursion(s1.substr(0, i), s2.substr(0, i)) && isScramble_recursion(s1.substr(i, s1.size()-i), s2.substr(i, s2.size()-i))) || 
          (isScramble_recursion(s1.substr(0, i), s2.substr(s2.size()-i, i)) && isScramble_recursion(s1.substr(i, s1.size()-i), s2.substr(0, s2.size()-i))))
        {
          // cout << "true" << endl;
          return true;
        }
      }
      return false;
    }

    static bool isScramble_DP(string s1, string s2)
    {
      if (s1.size()!=s2.size())
      {
        return false;
      }
      if(s1.size()==0 || s1==s2)
      {
        return true;
      }
      int length = s1.size();
      std::vector<std::vector<std::vector<bool> > > dp(length+1, vector<std::vector<bool> >(length, std::vector<bool>(length)));
      for (int i = 0; i < length; ++i)
      {
        for (int j = 0; j < length; ++j)
        {
          dp[1][i][j] = (s1[i]==s2[j]);
        }
      }
      for (int k = 2; k <= length ; ++k)
      {
        for (int i = 0; i < length-k+1; ++i)
        {
          for (int j = 0; j < length-k+1; ++j)
          {
            dp[k][i][j] = false;
            for (int div = 1; div < k && dp[k][i][j]==false; ++div)
            {
              dp[k][i][j] = (dp[div][i][j] && dp[k-div][i+div][j+div]) || (dp[k-div][i+div][j] && dp[div][i][j+k-div]); 
            }
          }
        }
      }
      return dp[length][0][0];
    }

};
int64_t getRealTimeUs()
{
  struct timeval tv;
  gettimeofday(&tv, NULL);
  return (int64_t)tv.tv_sec*1000000ll+tv.tv_usec;
}


int main ()
{
  string s1 = "abcdefghijklmnopq";
  string s2 = "efghijklmnopqcadb";

  // string s3 = "ragta";
  
  int64_t start = getRealTimeUs();
  bool r1 = Solution::isScramble_DP(s1, s2);
  int64_t cost1 = getRealTimeUs() - start;
  start = getRealTimeUs();
  bool r2 = Solution::isScramble_recursion(s1, s2);
  int64_t cost2 = getRealTimeUs() - start;
  cout << "r1 = " << r1 << endl;
  cout << " DP cost time = " << cost1 << " us" << endl; //cost 708 us
  cout << " Recursion cost time = " << cost2 << " us" << endl; // cost 6740684 us
  // cout << "r2 = " << r2 << endl;
	return 0;
}
