//source: https://leetcode.com/problems/palindrome-partitioning-ii/

/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/

#include <iostream>
#include <vector>
#include <map>
#include <limits.h>

using namespace std;

bool ispalidrome(string s) {
  int start = 0, end = s.size()-1;
  while(start < end){
    if (s[start] != s[end]) {
      return false;
    }
    start++;
    end--;
  }
  return true;
}
//Time Limit
int minCut(string s) {
  if (s.size() == 0) {
    return 0;
  }
  int res = 0;
  map<int, int> map;
  map[0] = res;
  for (int i = 0; i < s.size() ; ++i) {
    map[i+1] = INT_MAX;
    for (int j = i; j >= 0 ; --j) {
      if (ispalidrome(s.substr(j, i-j+1))){
        int tmp = map[j] + 1;
        map[i+1] = min(tmp, map[i+1]);
      }
    }
  }
  return map[s.size()] - 1;
}

// improve
int minCut_improve(string s) {
  bool matrix[s.size()][s.size()];
  for (int i = s.size()-1; i >= 0 ; --i) {
    for (int j = i; j < s.size() ; ++j) {
      if (s[i] == s[j] && ( (j - i) < 2 || matrix[i+1][j-1])) {
        matrix[i][j] = true;
      } else {
        matrix[i][j] = false;
      }
    }
  }
  vector<int> v(s.size(), 0);
  for (int i = 0; i < s.size() ; ++i) {
    v[i] = INT_MAX;
    for (int j = i; j >= 0 ; --j) {
      if (matrix[j][i]) {
        if (j == 0) {
          v[i] = 0;
        } else {
          int tmp = v[j-1]+1;
          v[i] = min(v[i], tmp);
        }
      }
    }
  }
  return v[s.size()-1];
}

int main ()
{
  string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  int res = minCut_improve(s);
  cout << "res = " << res << endl;
	return 0;
}
