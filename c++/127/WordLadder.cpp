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
#include <unordered_map>
#include <algorithm>
#include <string>
#include <queue>

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

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    unordered_map<string, int> dis;
    dis[beginWord] = 1;
    queue<string> queue;
    wordList.insert(endWord);
    queue.push(beginWord);

    while (queue.size() > 0)
    {
        string word = queue.front();
        queue.pop();
        cout << "word = " << word << endl;

        if (word == endWord)
        {
            break;
        }

        for (int i = 0; i < word.size(); ++i) {
            string temp = word;
            for (int j = 'a'; j <= 'z'; ++j) {
                temp[i] = j;
                if (wordList.count(temp) > 0 && dis.count(temp) == 0) {
                    dis[temp] = dis[word] + 1;
                    queue.push(temp);
                }
            }
        }
    }
    return dis.count(endWord) > 0 ? dis[endWord] : 0;
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
