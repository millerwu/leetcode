//source: https://leetcode.com/problems/word-break-ii/

/*
Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word is a valid dictionary word.

Return all such possible sentences.

For example, given
s = "catsanddog",
dict = ["cat", "cats", "and", "sand", "dog"].

A solution is ["cats and dog", "cat sand dog"].
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void printVector(vector<string>& s)
{
  cout << "print vector" << endl;
  for (int i = 0; i < s.size(); ++i) {
    cout << s[i] << endl;
  }
}


vector<string> wordBreak(string s, vector<string>& wordDict) {
  vector< vector<string> > result(s.size());

  for (int i = 0; i < s.size(); ++i) {
    string sub_s1 = s.substr(0, i+1);
    if (std::find(wordDict.begin(), wordDict.end(), sub_s1) != wordDict.end()) {
      result[i].push_back(sub_s1);
    }
    for (int j = 0; j < i; ++j) {
      string sub_s2 = s.substr(j+1, i-j);
      if (!result[j].empty()) {
        if (std::find(wordDict.begin(), wordDict.end(), sub_s2) != wordDict.end()) {
          for (int k = 0; k < result[j].size(); ++k) {
            result[i].push_back(result[j][k]+ " " + sub_s2);
          }
        }
      }
    }
  }
  return result[s.size()-1];
}

int main ()
{
  vector<string> dict = {"cat", "cats", "and", "sand", "dog"};
  string s = "catsandcatdog";
  cout << "input dict:"<< endl;
  printVector(dict);
  cout << "input string: " << endl;
  cout << s << endl;

  string s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
  vector<string> dict1 = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};

  vector<string> res = wordBreak(s, dict);
  cout << "res:" << endl;
  printVector(res);
	return 0;
}
