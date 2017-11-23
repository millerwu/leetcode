//source: https://leetcode.com/problems/reverse-integer/

/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

#include <iostream>
#include <vector>

/*
 * it may be overflow
 * 1534236469 -> 9646324351
 * 9646324351 is bigger than INT_MAX
 */

using namespace std;

int reverse(int x) {
	if (x == 0) {
		return x;
	}
	int64_t res = 0;
	while ( x != 0) {
		int a = x%10;
		x = x/10;
		res = res*10 + a;
	}
	if (res > INT_MAX || res < INT_MIN) {
		return 0;
	}
	return res;
}

int main ()
{
	int a = -123;
	int res = reverse(a);
	cout << "res = " << res << endl;
	return 0;
}
