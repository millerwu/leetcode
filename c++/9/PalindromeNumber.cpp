//source: https://leetcode.com/problems/palindrome-number/

/*
Determine whether an integer is a palindrome. Do this without extra space.

click to show spoilers.

 Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space.

You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

There is a more generic way of solving this problem.
*/

#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	bool isPalindrome(int x) {
		if (x < 0) return false;

		int x_ = 0;
		int a_x = x;
		while (a_x > 0) {
			x_ = x_*10 + a_x%10;
			a_x = a_x /10;
		}
		return x == x_;
	}
	return 0;
}
