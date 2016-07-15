//source: https://leetcode.com/problems/climbing-stairs/

/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    static int climbStairs(int n) {
        if (n==0)
            return 0;
        vector<int> m(n+1, 0);
        for (int i = 0; i< m.size(); i++)
        {
            if (i < 2)
            {
                m[i] = 1;
            } else {
                m[i] = m[i-1] + m[i-2];
            }
        }
        return m[n];
    }
};

int main (int argc, char** argv)
{
    int n = atoi(argv[1]);
    cout << n << " need " << Solution::climbStairs(n) << " steps" << endl;
	return 0;
}
