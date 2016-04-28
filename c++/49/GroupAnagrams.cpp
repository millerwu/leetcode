//source: https://leetcode.com/problems/anagrams/

/*
Given an array of strings, group anagrams together.

For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
Return:

[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

class Solution {
public:
    static vector< vector<string> > groupAnagrams(vector<string>& strs) {
    	vector< vector<string> > res;
    	std::map<string, int> m;
    	
    	for (int i = 0; i < strs.size(); ++i)
    	{
    		string word = strs[i];
    		sort(word.begin(), word.end());
    		if (m.find(word) == m.end())
    		{
    			vector<string> r;
    			r.push_back(strs[i]);
    			res.push_back(r);
    			m[word] = res.size() - 1;
    		} else {
    			res[m[word]].push_back(strs[i]);
    		}
    	}
    	for (int i = 0; i < res.size(); ++i)
    	{
    		sort(res[i].begin(), res[i].end());
    	}
    	return res;   
    }
};

void printAnagrams(vector< vector<string> > v)
{
	for (int i = 0; i < v.size(); ++i)
	{
		for (int j = 0; j < v[i].size(); ++j)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
}

int main ()
{
	string mystrings[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
	std::vector<string> v(mystrings, mystrings+sizeof(mystrings)/4);
	vector< vector<string> > res = Solution::groupAnagrams(v);

	printAnagrams(res);

	return 0;
}
