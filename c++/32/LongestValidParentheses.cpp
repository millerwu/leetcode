//source: https://leetcode.com/problems/longest-valid-parentheses/

/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring. 

For "(()", the longest valid parentheses substring is "()", which has length = 2. 

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4. 

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    static int longestValidParentheses(string s) {
    	if (s.length() <= 1)
    	{
    		return 0;
    	}
    	int res = 0;
        int longest = 0;
        int start = -1;

        std::vector<int> statck;

        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
            {
                statck.push_back(i);
            } else {
                if (statck.size() > 0)
                {
                    statck.pop_back();

                    int length = 0;

                    if (statck.size() ==0)
                    {
                        length = i - start;
                    } else {
                        length = i - statck.back();
                    }
                    if (length > longest)
                    {
                        longest = length;
                    }
                }
                else {
                    start = i;
                }

            }
        }
        return longest;
    }
};

int main ()
{
    string s = "()";
    int i = Solution::longestValidParentheses(s);
    cout<< "i = " << i << endl;
    pause();
	return 0;
}
