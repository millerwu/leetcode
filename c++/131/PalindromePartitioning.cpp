//source: https://leetcode.com/problems/palindrome-partitioning/

/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
  ["aa","b"],
  ["a","a","b"]
]
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;
bool ispalindrome(string s) {
  int start = 0, end = s.size()-1;
  while (start < end){
    if (s[start] != s[end]) {
      return false;
    }
    start++;
    end--;
  }
  return true;
}

vector<vector<string>> partition(string s) {
	vector<vector<string>> res;
  map<int, vector<vector<string>>> map;
  map[0] = res;
  for (int i = 0; i < s.size(); ++i) {
    vector<vector<string>> t;
    for (int j = i; j >= 0 ; --j) {
      if (ispalindrome(s.substr(j, i-j+1))){
        vector<vector<string>> tmp = map[j];
        if (tmp.size() == 0) {
          vector<string> vs;
          vs.push_back(s.substr(j, i-j+1));
          t.push_back(vs);
        } else {
          for (int k = 0; k < tmp.size(); ++k) {
            tmp[k].push_back(s.substr(j, i-j+1));
            t.push_back(tmp[k]);
          }
        }
      }
    }
    map[i+1] = t;
  }
  return map[s.size()];
}

void print(vector<vector<string>> s) {
  for (int i = 0; i < s.size() ; ++i) {
    for (int j = 0; j < s[i].size() ; ++j) {
      cout << s[i][j] << " ";
    }
    cout << endl;
  }
}


int main ()
{
  string test = "aabdb";
  vector<vector<string>> res = partition(test);
  print(res);
	return 0;
}
