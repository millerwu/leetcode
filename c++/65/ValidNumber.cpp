//source: https://leetcode.com/problems/valid-number/

/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

*/

#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

class Solution {
public:
    static bool isNumber(string s) {
        if(s.size() == 0)
		{
			return false;
		}

		if ( s[0] == 'e' || s[s.size()-1] == 'e')
			return false;
		
		bool spacein = false;
		bool spaceout = false;
		bool pointonce = false;
		bool eonce = false;
		for (int i = 0; i < s.size(); i++)
		{
			cout << " " << s[i];
			if (!isdigit(s[i]) && s[i]!='e' && s[i]!=' ' && s[i]!='.')
			return false;

			if (!spacein)
			{
				spacein = s[i]!=' ';
				continue;
			}
			if (s[i] == ' ')
			{
				spaceout = true;
				continue;
			} else {
				if (spaceout)
					return false;
			}
			if (s[i] == '.')
			{
				if (!pointonce)
				{
					pointonce = true;
				} else {
					return false;
				}
			}
			if (s[i] == 'e')
			{
				if (!eonce)
				{
					eonce = true;
				} else {
					return false;
				}
			}
			
		}
		if (s[0]==' ' && !spacein)
			return false;
		return true;
    }
};

int main ()
{
	string s1 = "   .";
	cout << "res = " << Solution::isNumber(s1) << endl;
	return 0;
}
