//source: https://leetcode.com/problems/valid-palindrome/

/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.


*/

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

bool isPalindrome(string s) {
	int start = 0;
	int end = s.size()-1;
	while (start < end) {
		if (!isalnum(s[start]))
		{
			++start;
			continue;
		}
		if (!isalnum(s[end]))
		{
			--end;
			continue;
		}
		if (s[start] == s[end] || (isalpha(s[start]) && isalpha(s[end]) && abs(s[start] - s[end]) == 32))
		{
			++start;
			--end;
			continue;
		} else {
			return false;
		}
	}
  return true;
}			

int main ()
{
	string s = "aaa";
	string s1 = "A man, a plan, a canal: Panama";
	string s2 = "race a car";
	cout << isPalindrome(s) << endl;
	cout << isPalindrome(s1) << endl;
	cout << isPalindrome(s2) << endl;
	return 0;
}
