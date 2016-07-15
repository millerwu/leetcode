//source: https://leetcode.com/problems/valid-number/
//

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

bool isspace(const char c)
{
	return (c == ' ' || c == '\t' || c=='\n' || c=='\r' || c=='\f' || c=='\v');
}

class Solution {
public:
    static bool isNumber(string s) {
        if(s.size() == 0)
		{
			return false;
		}
		
		int index = 0;
		while (isspace(s[index]))
			index++;

		if (s[index] == '\0') return false;

		if (s[index] == '-' || s[index]=='+')
			index++;
		bool hasE = false;
		bool point = false;

		const int head = index;
		
		while (index < s.size())
		{
			// if meet '.'
			if (s[index] == '.')
			{
				if (hasE || point)
				{
					return false;
				}
				if (head==index && !isdigit(s[index+1]) )
					return false;
				point = true;
				index++;
				continue;
			}
			// if meet 'e'
			if (s[index] == 'e')
			{
				if (hasE || index == head)
				{
					return false;
				}
				index++;
				if (s[index] == '-' || s[index] == '+')
					index++;
				if (!isdigit(s[index]))
					return false;
				hasE = true;
				index++;
				continue;
			}
			//if meet ' '
			if (s[index] == ' ')
			{
				index++;
				while (index < s.size())
				{
					if (s[index++] == ' ')
						continue;
					else {
						return false;
					}
				}
				return true;
			}
			if (!isdigit(s[index]))
				return false;
			index++;
		}
		return true;
    }
};

#define TEST(x) cout << x << " res = " << Solution::isNumber(x) << endl
int main ()
{
	string s1 = "   ";
	TEST("1e1");
	TEST("1.044");
    TEST(" 1.044 ");
    TEST("1.a");
    TEST("abc");
    TEST("e");
    TEST("0e ");
    TEST("1e2");
    TEST("");
    TEST(" ");
    TEST("1.");
    TEST(".2");
    TEST(" . ");
    TEST(".");
    TEST("1.2.3");
    TEST("1e2e3");
    TEST("1..");
    TEST("+1.");
    TEST(" -1.");
    TEST("6e6.5");
    TEST("005047e+6");
	return 0;
}
