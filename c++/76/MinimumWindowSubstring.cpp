//source: https://leetcode.com/problems/minimum-window-substring/

/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".
*/

#include <iostream>
#include <string>
#include <string.h>
#include <climits>

using namespace std;

class Solution {
public:
    static string minWindow(string s, string t) {
        string win;
        if (s.size() <= 0 || t.size() <= 0 || s.size() < t.size())
        {
            return win;
        }
        const int max_chars = 256;
        const int c_not_exit = -1;
        const int c_not_found = 0;

        int m[max_chars], f[max_chars];
        memset(m, c_not_exit, sizeof(m));
        memset(f, c_not_exit, sizeof(f));

        for (int i=0; i<t.size(); ++i)
        {
            m[t[i]] == c_not_exit ? m[t[i]] = 1: m[t[i]]++;
            f[t[i]] = c_not_found;
        }
        int winSize = INT_MAX;
        int letter = 0;
        int begin = 0;
        int start = -1;

        for (int i = 0; i<s.size(); ++i)
        {
            if (m[s[i]] != c_not_exit)
            {
                char ch = s[i];
                f[ch]++;

                if (f[ch] <= m[ch])
                {
                    letter++;
                }
                cout << "letter = " << letter << endl;
                if (letter>=t.size())
                {
                    while (f[s[begin]] > m[s[begin]] || f[s[begin]] == c_not_exit)
                    {
                        if (f[s[begin]] > m[s[begin]])
                        {
                            f[s[begin]]--;
                        }
                        begin++;
                    }

                    if (winSize > i-begin+1)
                    {
                        winSize = i-begin+1;
                        start = begin;
                    }
                }
            }
        }
        cout << "start = " << start << " winSize = " << winSize << endl;
        if (start>=0 && winSize>0)
        {
            win = s.substr(start, winSize);
        }
        return win;
    }
};

int main ()
{
    string s1 = "ADOBECODEBANC";
    string s2 = "ABC";

    string r = Solution::minWindow(s1, s2);
    cout << "result = " << r << endl;
	return 0;
}
