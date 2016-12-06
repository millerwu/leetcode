//source: https://leetcode.com/problems/longest-substring-without-repeating-characters/

/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int lengthOfLongestSubstring(string s) {
	int dirct[256];
	memset(dirct, -1, sizeof dirct);
	int last = -1;
	int max = 0;

	for (int i = 0; i < s.size() ; ++i) {
		if (dirct[s[i]] != -1 && dirct[s[i]] > last) {
			last = dirct[s[i]];
		}
		max = ::max(i - last, max);
		dirct[s[i]] = i;
	}
	return max;
}

int main ()
{
	string s = "tmmzuxt";
	int res = lengthOfLongestSubstring(s);
	cout << "res = " << res << endl;
	return 0;
}
