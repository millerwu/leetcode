//source: https://leetcode.com/problems/word-ladder/

/*
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

Given:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>

using namespace std;

int differChar(string s1, string s2) {
	int count = 0;
	for (int i = 0; i < s1.size(); i++)
	{
		if (s1[i] != s2[i])
		{
			++count;
		}
	}
	return count;
} 

void ladderLengthHelper(string beginWord, string endWord, unordered_set<string>& wordList, vector<string>& stackList, int& res) {
	if (differChar(beginWord, endWord) <= 1)
	{
		int temp_res = stackList.size() + 2;
		res = res > temp_res ? temp_res : res;
		return;
	}
	for (auto word : wordList)	
	{
		cout << "word = " << word << endl;
		if (differChar(beginWord, word) == 1)
		{
			cout << "beginWord = " << beginWord << endl;
			wordList.erase(word);
			cout << "line = " << __LINE__ << endl;
			stackList.push_back(word);
			cout << "line = " << __LINE__ << endl;
			ladderLengthHelper(word, endWord, wordList, stackList, res);
			cout << "line = " << __LINE__ << endl;
			stackList.pop_back();	
			cout << "line = " << __LINE__ << endl;
			cout << "word1 =  " << word << endl;
			wordList.insert(word);
			cout << "line = " << __LINE__ << endl;
		}
	}
}

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
  int res = 0;
  vector<string> outputList;
  if (beginWord == endWord || wordList.size() <= 0)
  {
  	return res;
  }
  ladderLengthHelper(beginWord, endWord, wordList, outputList, res);
  return res;  
}



int main ()
{
	string beginWord = "hit";
	string endWord = "cog";
	unordered_set<string> wordList = {"hot", "dot", "dog", "lot", "log"};
	int res = ladderLength(beginWord, endWord, wordList);
	cout << "res = " << res << endl;
	return 0;
}
