//source: https://leetcode.com/problems/length-of-last-word/

/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

#include <iostream>
#include <string>

class Solution {
public:
    static int lengthOfLastWord(string s) {
		if (s.length()==0)
			return 0;
		int res = 0;
		int i = s.length()-1;
		while (i >= 0)
		{
			if (s[i]==' ')
			{
				i--;
				continue;
			} else {
				break;
			}
		}
		
        for (; i >= 0; i--)
		{
			if (s[i] == ' ')
				break;
			res++;
		}
		return res;
    }
};

int main ()
{
	string s = "Hello World";
	int length = Solution::lengthOfLastWord(s);
	cout << "length = " << length << endl;
	return 0;
}
