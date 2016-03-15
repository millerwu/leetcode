//source: https://leetcode.com/problems/wildcard-matching/

/*
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

#include <iostream>

class Solution {
public:
    bool isMatch(string s, string p) {

    	int s_index = 0;

        for (int i = 0; i < p.size(); ++i)
        {
        	if (p[i] == '*')
        	{
        		for (int j = index; j < s.size(); ++j)
        		{
        			
        		}
        	} else if (p[i] == '?' || p[i] == s[s_index])
        	{
        		s_index++;
        	} else {
        		return false;
        	}
        	
        }
    }
};

int main ()
{
	return 0;
}
