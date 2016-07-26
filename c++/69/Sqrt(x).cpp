//source:https://leetcode.com/problems/sqrtx/

/*
Implement int sqrt(int x).

Compute and return the square root of x.

*/

#include <iostream>

using namespace std;

class Solution {
public:
    static int mySqrt(int x) {
        long long l = 0;
        long long r = (x/2)+1;
        while (l <= r) 
        {
            long long mid = (l+r)/2;
            long long s = mid * mid;
            if (s == x)
            {
                return mid;
            } 
            else if (s < x) {
                l = mid + 1;
            } else {
                r = mid - 1; 
            }
        }
        return r;     
    }
};
#define TEST_SQRT(X) cout << X << " sqrt is " << Solution::mySqrt(X)<< endl;

int main (int argc, char** argv)
{
    int x = atoi(argv[1]);
    TEST_SQRT(x);
	return 0;
}
