//source: https://leetcode.com/problems/powx-n/

/*
Implement pow(x, n).
*/

#include <iostream>

class Solution {
public:
	static double pow(double x, int n)
	{
		if (n == 0)
		{
			return 1;
		}
		double v = pow(x, n/2);

		if (n%2 == 0)
		{
			return v * v;
		} else {
			return v * v * x;
		}
	}

	static double myPow(double x, int n) {
		if (n < 0)
		{
			return 1.0/pow(x, -n);
		}else {
			return pow(x, n);
		}
    }
};

int main ()
{
	double x = Solution::myPow(2.33, 10);
	cout << x << endl;
	return 0;
}
