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
#include <string>

class Solution {
public:
    static bool isMatch(string s, string p) {

    	int s_index = 0;
        int p_index = 0;
        int last_s = -1;
        int last_p = -1;

        while (s_index < s.size()) {
            if (p[p_index] == '*')
            {
                p_index++;
                if (p_index == p.size())
                {
                    return true;
                }
                //for store the index of last '*' pos
                last_p = p_index;
                last_s = s_index;
            } else if (p[p_index] == s[s_index] || p[p_index] == '?') {
                p_index++;
                s_index++;
            } else if (last_s != -1) {
                //if the char is not match; than roll back to last '*' position.
                p_index = last_p;
                s_index = ++last_s;
            } else {
                return false;
            }
        }
        while (p[p_index] == '*')
            p_index++;

        return p_index==p.size();
    }
};

int main ()
{
    string s = "aa";
    string p = "*a";
    bool match = Solution::isMatch(s, p);

    cout << "match = " << match << endl;

	return 0;
}
